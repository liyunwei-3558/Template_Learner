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
//这是这个类的定义文件
#include <ros/ros.h>
#include "template.hpp"//在hpp中做好了类和成员函数的声明
#include <sstream>

namespace ns_template //定义了一个命名空间
 {
// Constructor 构造函数
Template::Template(ros::NodeHandle &nh) : nh_(nh) {        
     //input nodeHandle from TemplateHandle class, you can loadParameters, subscribeToTopics and publishToTopics too, if neccesary.
    //直接初始化了nh_成员变量，为传进来的nh
};

// Getters
fsd_common_msgs::ConeDetections Template::getConeDetections() { return cone_current; }      //push the data to TemplateHandle for publishing msg
//成员函数，获取cone_current
// Setters
void Template::setConeDetections(fsd_common_msgs::ConeDetections cones) {
    cone_current = cones;                               //get the callback msg from the 'TemplateHandle' class aimed to surport the runAlgorithm function to deal with data.
}

void Template::runAlgorithm() {     //your algorithm

}

}
