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

#include <ros/ros.h>
#include "template_handle.hpp"

typedef ns_template::TemplateHandle TemplateHandle;//相当于“唤醒”了这个命名空间下的这个类，简化代码

int main(int argc, char **argv) {
  ros::init(argc, argv, "template");                      //init node
  ros::NodeHandle nodeHandle("~");
  TemplateHandle myTemplateHandle(nodeHandle);            //init a TemplateHandle class, which input a nodeHandle for loadParameters, subscribeToTopics and publishToTopics
  ros::Rate loop_rate(myTemplateHandle.getNodeRate());    //get and set loop_rate
  while (ros::ok()) {

    myTemplateHandle.run();         //run from TemplateHandle class

    ros::spinOnce();                // Keeps node alive basically
    loop_rate.sleep();              // Sleep for loop_rate
  }
  return 0;
}

