/*
* File:   main.cpp
* Author: sagar
*
* Created on 10 September, 2012, 7:48 PM
*/
 #include <ros/ros.h>
 #include <visualization_msgs/Marker.h>
 #include <cstdlib>

 #include <cmath>
#include <iostream>
 
 #include "std_msgs/String.h"
#include <std_msgs/Float32.h>

using namespace std;

int main(int argc, char** argv) {

    ros::init(argc, argv, "heart");
    ros::NodeHandle n;
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("heart", 10);
    ros::Publisher reg_marker = n.advertise<visualization_msgs::Marker>("segment_marker", 10);

    ros::Rate r(30);
  
 	ros::NodeHandle position;
	std_msgs::Float32 msg;

   	visualization_msgs::Marker point, points, line_strip, line_list;


//////////////////////////////////////////


	
	points.header.frame_id = line_strip.header.frame_id = line_list.header.frame_id =  "/aurora";
	points.header.stamp = line_strip.header.stamp = line_list.header.stamp =  ros::Time::now();
	points.ns = line_strip.ns = line_list.ns = "circle";
	points.action = line_strip.action = line_list.action = visualization_msgs::Marker::ADD;
	points.pose.orientation.w = line_strip.pose.orientation.w = line_list.pose.orientation.w = 1.0;



	line_strip.id = 1;
	line_list.id = 2;

	points.type = visualization_msgs::Marker::SPHERE;
	line_strip.type = visualization_msgs::Marker::LINE_STRIP;
	line_list.type = visualization_msgs::Marker::LINE_LIST;

	points.scale.x =.31;
	points.scale.y = .31;
	points.scale.z =.31;

	// LINE_STRIP/LINE_LIST markers use only the x component of scale, for the line width
	line_strip.scale.x = 0.1;
	line_list.scale.x = 0.1;

	// Points are green
	points.color.r = 1.0f;
	points.color.g = 0.0f;
	points.color.a = 1;


	// Line strip is blue
	line_strip.color.g = 1.0;
	line_strip.color.a = 1.0;

	// Line list is red
	line_list.color.r = 1.0;
	line_list.color.a = 1.0;

    geometry_msgs::Point p;


/////



	point.type = visualization_msgs::Marker::MESH_RESOURCE;
	point.mesh_resource = "package://vision_t/change_orig_heart2.STL";
	point.header.frame_id = "/aurora";
	point.header.stamp = ros::Time::now();
	point.ns = "heart_mesh";
	//point.action = visualization_msgs::Marker::ADD;
	
	
	point.pose.orientation.w = 1;//1;
   	point.pose.orientation.x = 0.00;//1.004; //blue
   	point.pose.orientation.y = 0.015;//0.01; //gree
   	point.pose.orientation.z = -0.01;//0;
	
	point.scale.x =.1;
	point.scale.y =.1;
	point.scale.z =.1;

	point.pose.position.x = -27.9; //10; //-7;//-10;
	point.pose.position.y = -8.3;//-25; //-21.6;//20;
	point.pose.position.z = -9.8; // 0;//-9.8;

	// LINE_STRIP/LINE_LIST markers use only the x component of scale, for the line width
	
	// Points are green
	point.color.r = 0.5f;
	point.color.g = 0.1f;
	//point.color.b = 0.0;
	point.color.a = .3;



//////////////////////////////////

while (ros::ok()) {


marker_pub.publish(point);


//////
    



	points.id = 1;
      p.x = -11.297;
      p.y= 3.894;
      p.z= 0.602;


 	points.points.push_back(p);
	line_strip.points.push_back(p);

points.pose.position.x = p.x;
points.pose.position.y = p.y;
points.pose.position.z = p.z;



marker_pub.publish(points);

	points.id = 2;

      p.x= -12.402;
      p.y= 5.022;
      p.z= 0.057;




 	points.points.push_back(p);
	line_strip.points.push_back(p);

points.pose.position.x = p.x;
points.pose.position.y = p.y;
points.pose.position.z = p.z;



marker_pub.publish(points);

	points.id = 3;

      p.x= -11.477;
      p.y= 3.131;
      p.z= -0.705;
      
 	points.points.push_back(p);
	line_strip.points.push_back(p);

points.pose.position.x = p.x;
points.pose.position.y = p.y;
points.pose.position.z = p.z;



marker_pub.publish(points);

	points.id = 4;

p.x= -16.285;
      p.y= 4.065;
      p.z= 3.53;

 	points.points.push_back(p);
	line_strip.points.push_back(p);

points.pose.position.x = p.x;
points.pose.position.y = p.y;
points.pose.position.z = p.z;



marker_pub.publish(points);

	points.id = 5;
    
    p.x= -16.583;
      p.y= 5.627;
      p.z= 2.832;

 	points.points.push_back(p);
	line_strip.points.push_back(p);

points.pose.position.x = p.x;
points.pose.position.y = p.y;
points.pose.position.z = p.z;

marker_pub.publish(points);

//entrance


	points.id = 6;

   p.x= -23.948;
      p.y= 0.997;
      p.z= 2.341;



 	points.points.push_back(p);
	line_strip.points.push_back(p);

points.pose.position.x = p.x;
points.pose.position.y = p.y;
points.pose.position.z = p.z;



marker_pub.publish(points);

	points.id = 7;

     p.x= -24.51;
      p.y= 1.126;
      p.z= 0.109;



 	points.points.push_back(p);
	line_strip.points.push_back(p);

points.pose.position.x = p.x;
points.pose.position.y = p.y;
points.pose.position.z = p.z;



marker_pub.publish(points);

	points.id = 8;


      p.x= -24.48;
      p.y= 1.167;
      p.z= 0.14;



 	points.points.push_back(p);
	line_strip.points.push_back(p);

points.pose.position.x = p.x;
points.pose.position.y = p.y;
points.pose.position.z = p.z;



marker_pub.publish(points);
	points.id = 9;


  p.x= -20.045;
      p.y= -7.948;
      p.z= 1.406;



 	points.points.push_back(p);
	line_strip.points.push_back(p);

points.pose.position.x = p.x;
points.pose.position.y = p.y;
points.pose.position.z = p.z;



marker_pub.publish(points);



marker_pub.publish(points);
	points.id = 10;


 


      p.x= -23.107;
      p.y= -7.835;
      p.z= -10.426;



 	points.points.push_back(p);
	line_strip.points.push_back(p);

points.pose.position.x = p.x;
points.pose.position.y = p.y;
points.pose.position.z = p.z;



marker_pub.publish(points);

marker_pub.publish(points);
	points.id = 11;


 



p.x= -23.963;
      p.y= 8.22;
      p.z= -10.5;



 	points.points.push_back(p);
	line_strip.points.push_back(p);

points.pose.position.x = p.x;
points.pose.position.y = p.y;
points.pose.position.z = p.z;



marker_pub.publish(points);

marker_pub.publish(points);
	points.id = 12;


 


      p.x= -13.628;
      p.y= -7.98;
      p.z= -10.298;



 	points.points.push_back(p);
	line_strip.points.push_back(p);

points.pose.position.x = p.x;
points.pose.position.y = p.y;
points.pose.position.z = p.z;



marker_pub.publish(points);

	points.id = 13;


 


      p.x= -13.916;
      p.y= 8.43;
      p.z= -10.206;




 	points.points.push_back(p);
	line_strip.points.push_back(p);

points.pose.position.x = p.x;
points.pose.position.y = p.y;
points.pose.position.z = p.z;



marker_pub.publish(points);

	points.id = 14;


 

      p.x= -13.749;
      p.y= 0.864;
      p.z= 5.14;




 	points.points.push_back(p);
	line_strip.points.push_back(p);

points.pose.position.x = p.x;
points.pose.position.y = p.y;
points.pose.position.z = p.z;



marker_pub.publish(points);
	points.id = 15;


      p.x= -13.658;
      p.y= -2.984;
      p.z= -3.9;




 	points.points.push_back(p);
	line_strip.points.push_back(p);

points.pose.position.x = p.x;
points.pose.position.y = p.y;
points.pose.position.z = p.z;



marker_pub.publish(points);

	points.id = 16;


      p.x= -13.554;
      p.y=-0.472;
      p.z= -3.852;




 	points.points.push_back(p);
	line_strip.points.push_back(p);

points.pose.position.x = p.x;
points.pose.position.y = p.y;
points.pose.position.z = p.z;



marker_pub.publish(points);

	points.id = 19;


      p.x= -16.438;
      p.y=-2.218;
      p.z= 1.428;




 	points.points.push_back(p);
	line_strip.points.push_back(p);

points.pose.position.x = p.x;
points.pose.position.y = p.y;
points.pose.position.z = p.z;



marker_pub.publish(points);
}


return 0;
}

 ////////////////////// CHECK!!!! SIZE WHEN IS FAILED!!!!
