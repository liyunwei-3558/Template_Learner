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
//.hpp这是类的声明文件
#ifndef TEMPLATE_HPP //防止重复定义 TEMPLATE_HPP
#define TEMPLATE_HPP

#include "fsd_common_msgs/ConeDetections.h" //包含了这两种消息类型
#include "std_msgs/String.h"

namespace ns_template {

class Template { 

 public:
  // Constructor
  Template(ros::NodeHandle& nh);//构造函数，与类同名， 传引用参数是一个句柄

	// Getters
  fsd_common_msgs::ConeDetections getConeDetections();//一个获取成员变量具体值的函数，返回类型是公用消息包中的ConeDetections类型

	// Setters
  void setConeDetections(fsd_common_msgs::ConeDetections cones);


  void runAlgorithm();

private:

	ros::NodeHandle& nh_;//句柄类型成员变量nh_
	
	fsd_common_msgs::ConeDetections cone_current;

};
}

#endif //TEMPLATE_HPP
