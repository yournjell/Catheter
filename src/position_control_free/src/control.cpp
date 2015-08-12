
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <std_msgs/Float32.h>
#include <iostream>
#include <sstream>
#include <math.h>
//#include <globals.h>

using namespace std;

float tension_w,tension_w2,tension_w3, tension_w4, tension_v1,  tension_v2,  tension_v3,tension_v4, shaft_x1, shaft_x2, shaft_y1, shaft_y2,shaft_z1, shaft_z2;
float side_f_0a, side_f_0b,side_f_1a, side_f_1b,side_f_2a, side_f_2b,side_f_3a, side_f_3b;
float printt(float g);
/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
// %Tag(CALLBACK)%





void side_f_p1(const std_msgs::Float32 & msg)
{
side_f_0a = msg.data;
 //ROS_INFO("1: [%f]", tension_w);

side_f_0b = printt(side_f_0a);

}


void side_f_p2(const std_msgs::Float32 & msg)
{
side_f_1a = msg.data;
 //ROS_INFO("1: [%f]", tension_w);

side_f_1b = printt(side_f_1a);

}


void side_f_p3(const std_msgs::Float32 & msg)
{
side_f_2a = msg.data;
 //ROS_INFO("1: [%f]", tension_w);

side_f_2b = printt(side_f_2a);

}


void side_f_p4(const std_msgs::Float32 & msg)
{
side_f_3a = msg.data;
 //ROS_INFO("1: [%f]", tension_w);

side_f_3b = printt(side_f_3a);

}



void shaft_x(const std_msgs::Float32 & msg)
{
shaft_x1 = msg.data;
 //ROS_INFO("1: [%f]", tension_w);

shaft_x2 = printt(shaft_x1);

}

void shaft_y(const std_msgs::Float32 & msg)
{
shaft_y1 = msg.data;
 //ROS_INFO("1: [%f]", tension_w);

shaft_y2 = printt(shaft_y1);

}

void shaft_z(const std_msgs::Float32 & msg)
{
shaft_z1 = msg.data;
 //ROS_INFO("1: [%f]", tension_w);

shaft_z2 = printt(shaft_z1);

}

void tension1(const std_msgs::Float32 & msg)
{
tension_w = msg.data;
 //ROS_INFO("1: [%f]", tension_w);

tension_v1 = printt(tension_w);


}


void tension2(const std_msgs::Float32 & msg)
{
tension_w2 = msg.data;
 //ROS_INFO("1: [%f]", tension_w);

tension_v2 = printt(tension_w2);


}


void tension3(const std_msgs::Float32 & msg)
{
tension_w3 = msg.data;
 //ROS_INFO("1: [%f]", tension_w);

tension_v3 = printt(tension_w3);


}


void tension4(const std_msgs::Float32 & msg)
{
tension_w4 = msg.data;
 //ROS_INFO("1: [%f]", tension_w);

tension_v4 = printt(tension_w4);


}



float printt(float b){
//ROS_INFO("here");
//cout<< b<<endl;
return b;
}




int main(int argc, char **argv)
{
  ros::init(argc, argv, "control");


  ros::NodeHandle n, de_t;
  std_msgs::Float32 msg;


  ros::Subscriber sub1 = n.subscribe("tension11", 100, tension1);
  ros::Subscriber sub2 = n.subscribe("tension21", 100, tension2);
  ros::Subscriber sub3 = n.subscribe("tension31", 100, tension3);
  ros::Subscriber sub4 = n.subscribe("tension41", 100, tension4);

  ros::Subscriber sub5 = n.subscribe("shaft_x", 100, shaft_x);
  ros::Subscriber sub6 = n.subscribe("shaft_y", 100, shaft_y);
  ros::Subscriber sub7 = n.subscribe("shaft_z", 100, shaft_z);

  ros::Subscriber sub8 = n.subscribe("side_f_0", 100, side_f_p1);
  ros::Subscriber sub9 = n.subscribe("side_f_1", 100, side_f_p2);
  ros::Subscriber sub10 = n.subscribe("side_f_2", 100, side_f_p3);
  ros::Subscriber sub11 = n.subscribe("side_f_3", 100, side_f_p4);
 

ros::Publisher desired_tz1_pub= de_t.advertise<std_msgs::Float32>("desired_tz1", 100);
ros::Publisher desired_tz2_pub= de_t.advertise<std_msgs::Float32>("desired_tz2", 100);
ros::Publisher desired_ty1_pub= de_t.advertise<std_msgs::Float32>("desired_ty1", 100);
ros::Publisher desired_ty2_pub= de_t.advertise<std_msgs::Float32>("desired_ty2", 100);
ros::Publisher desired_dis_pub= de_t.advertise<std_msgs::Float32>("desired_dis", 100);
ros::Publisher desired_dir_pub= de_t.advertise<std_msgs::Float32>("desired_dir", 100);

  ros::Rate loop_rate(100);
while(ros::ok()){

cout<<"  ttt  "<<tension_v1<<"  ttt  " <<tension_v2<<"  ttt  " <<tension_v3<<"  ttt  " <<tension_v4<<endl;


cout<<"  shaft_x  "<<shaft_x2<<"  shaft_y  " <<shaft_y2<<"  shaft_z  " <<shaft_z2<<endl;


float global_px,global_py,global_pz;

      global_px = abs((side_f_1b/1.17)-637); //position_side_final[i][3] and position_side_final[i][

 if((side_f_1b/1.17)<5)  {     global_px = abs(side_f_3b-479); //position_side_final[i][3] and position_side_final[i][1]

}    
       global_py = abs((side_f_0b)-411);
      
       global_pz = abs((side_f_2b/1.2-282));//((position_side_final[i][2]/4.08)-(457/4.08))*0.1;




cout<<"  gx "<<global_px<<"  gy  " <<global_py<<"  gz  " <<global_pz<<endl;



float dtenz1,dtenz2,dteny1,dteny2,dtenx, dirr;

dtenz1 = 0.70;
dtenz2 = 0.00;
dteny1 = 0.00;
dteny2 = 0.00;
dtenx = 2.55;
dirr = 2;

msg.data = dtenz1;
desired_tz1_pub.publish(msg);
msg.data = dtenz2;
desired_tz2_pub.publish(msg);
msg.data = dteny1;
desired_ty1_pub.publish(msg);
msg.data = dteny2;
desired_ty2_pub.publish(msg);
msg.data = dtenx;
desired_dis_pub.publish(msg);
msg.data = dirr;
desired_dir_pub.publish(msg);




        ros::spinOnce();
        loop_rate.sleep();
    }

  return 0;
}





















