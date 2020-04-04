/*
    Formula Student Driverless Project (FSD-Project).
    Copyright (c) 2019:
     - chentairan <killasipilin@gmail.com>

    FSD-Project is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    FSD-Project is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FSD-Project.  If not, see <https://www.gnu.org/licenses/>.
*/
//TemplateHandle 的实现代码
#include <ros/ros.h>
#include "template_handle.hpp"

namespace ns_template {

// Constructor
TemplateHandle::TemplateHandle(ros::NodeHandle &nodeHandle) :
    nodeHandle_(nodeHandle),
    template_(nodeHandle) //构造函数，对两个成员变量nodeHandle_和template_都初始化为传进来的这个句柄
{
  ROS_INFO("Constructing Handle");
  loadParameters();//加载param参数
  subscribeToTopics();//订阅话题
  publishToTopics();//发布话题
}

// Getters
int TemplateHandle::getNodeRate() const { return node_rate_; }      //return node rate to main.cpp, the node_rate_ is loaded by loadParameters function.

// Methods
void TemplateHandle::loadParameters() {    //从yaml文件传入parameter                         //load parameters from ./config/template.yaml, you can change it without rebuilding the program.
  ROS_INFO("loading handle parameters");
  if (!nodeHandle_.param<std::string>("vision_cone_detections_topic_name",
                                      vision_cone_detections_topic_name_,
                                      "/perception/vision/cone_detections")) {
    ROS_WARN_STREAM("Did not load vision_cone_detections_topic_name. Standard value is: " << vision_cone_detections_topic_name_);
  }
  if (!nodeHandle_.param<std::string>("template_state_topic_name",
                                      template_state_topic_name_,
                                      "/perception/vision/state")) {
    ROS_WARN_STREAM("Did not load template_state_topic_name. Standard value is: " << template_state_topic_name_);
  }
  if (!nodeHandle_.param("node_rate", node_rate_, 1)) {
    ROS_WARN_STREAM("Did not load node_rate. Standard value is: " << node_rate_);
  }
}

void TemplateHandle::subscribeToTopics() {//话题订阅函数
  ROS_INFO("subscribe to topics");
  visionConeDetectionsSubscriber_ = nodeHandle_.subscribe(vision_cone_detections_topic_name_, 1, &TemplateHandle::visionConeDetectionsCallback, this);
}

void TemplateHandle::publishToTopics() {//话题发布的函数,激活这个要发布的话题，但尚未发布数据
  ROS_INFO("publish to topics");
  templateStatePublisher_ = nodeHandle_.advertise<fsd_common_msgs::ConeDetections>(template_state_topic_name_, 1);
}

void TemplateHandle::run() {//运算
	template_.runAlgorithm();       //run algorithm from Template class
  sendMsg();                      //after running algorithm, you can send the data you want to a topic, which is defined at publishToTopics
}

void TemplateHandle::sendMsg() {//发送数据，底下这个是Template的成员函数，返回获取的ConeDetections类型信息
  templateStatePublisher_.publish(template_.getConeDetections());     //this example assume we sent a 'fsd_common_msgs::ConeDetections' type msg, you can change it to any others.
}

void TemplateHandle::visionConeDetectionsCallback(const fsd_common_msgs::ConeDetections &cones) {
  template_.setConeDetections(cones);       //push the callback msg to the class 'template_' aimed to surport the runAlgorithm function to deal with data.
}
}


/********************Attention********************/
//the variables from this file which you can't find definition will be defined at './include/template_handle.hpp'.