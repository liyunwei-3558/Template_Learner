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

#ifndef TEMPLATE_HANDLE_HPP
#define TEMPLATE_HANDLE_HPP

#include "fsd_common_msgs/ConeDetections.h"
#include "template.hpp"

namespace ns_template {

class TemplateHandle {

 public:
  // Constructor
  TemplateHandle(ros::NodeHandle &nodeHandle); //构造函数，参数是ros类中的句柄

//  // Getters
  int getNodeRate() const;

  // Methods  一堆成员函数
  void loadParameters();
  void subscribeToTopics();
  void publishToTopics();
  void run();
  void sendMsg();
//  void sendVisualization();

 private://私有成员变量和函数
  ros::NodeHandle nodeHandle_; 
  ros::Subscriber visionConeDetectionsSubscriber_;//订阅者
  ros::Publisher templateStatePublisher_;//发布者

  void visionConeDetectionsCallback(const fsd_common_msgs::ConeDetections &cones);
//回调函数
  std::string vision_cone_detections_topic_name_;
  std::string template_state_topic_name_;

  int node_rate_; //这一节点的频率，是从.yaml文件得到的

  Template template_;//一个template类

};
}

#endif //TEMPLATE_HANDLE_HPP
