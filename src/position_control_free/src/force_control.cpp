 #include <ros/ros.h>
 #include <visualization_msgs/Marker.h>
 #include <cstdlib>

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <std_msgs/Float64.h>
#include <std_msgs/Float32.h>
#include <iostream>
#include <sstream>
#include <math.h>
#include <tension_m/tension.h>
#include "geometry_msgs/PoseArray.h"
#include <geometry_msgs/WrenchStamped.h>

using namespace std;

float tension_w,tension_w2,tension_w3, tension_w4, tension_v1,  tension_v2,  tension_v3,tension_v4, shaft_x1, shaft_x2, shaft_y1, shaft_y2,shaft_z1, shaft_z2;
float side_f_0a, side_f_0b,side_f_1a, side_f_1b,side_f_2a, side_f_2b,side_f_3a, side_f_3b;
float printt(float g);
float aurora1_x, aurora1_y, aurora1_z, aurora2_x, aurora2_y , aurora2_z, aurora1_ori_x, aurora1_ori_y, aurora1_ori_z, aurora2_ori_x, aurora2_ori_y, aurora2_ori_z;
float  top_x, top_y, top_z, top_ori_x, top_ori_y, top_ori_z, bot_ori_x, bot_ori_y, bot_ori_z, bot_x, bot_y, bot_z;  
float nano_fx, nano_fz, nano_fy, nano_mx, nano_my, nano_mz, s_fx, s_fy, s_fz, s_mx, s_my, s_mz;    
void tension1(const tension_m::tension & msg2)
{
tension_w = msg2.tension1;
 tension_w2 = msg2.tension2;
 tension_w3 = msg2.tension3;
 tension_w4 = msg2.tension4;
 //ROS_INFO("1: [%f]", tension_w);

tension_v1 = printt(tension_w);
tension_v2 = printt(tension_w2);
tension_v3 = printt(tension_w3);
tension_v4 = printt(tension_w4);


}
void nano17re(const geometry_msgs::WrenchStamped & nano17){

nano_fx = -nano17.wrench.force.x;
nano_fy = -nano17.wrench.force.y;
nano_fz = -nano17.wrench.force.z;
nano_mx = -nano17.wrench.torque.x;
nano_my = -nano17.wrench.torque.y;
nano_mz = -nano17.wrench.torque.z;


s_fx = printt(nano_fx);
s_fy = printt(nano_fy);
s_fz = printt(nano_fz);
s_mx = printt(nano_mx);
s_my = printt(nano_my);
s_mz = printt(nano_mz);

}

void aurora(const geometry_msgs::PoseArray & msg3)
{
 aurora1_x = msg3.poses.at(0).position.x;
 aurora1_y = msg3.poses.at(0).position.y;
 aurora1_z = msg3.poses.at(0).position.z;
 aurora2_x = msg3.poses.at(1).position.x;
 aurora2_y = msg3.poses.at(1).position.y;
 aurora2_z = msg3.poses.at(1).position.z;

 aurora1_ori_x = msg3.poses.at(0).orientation.x;
 aurora1_ori_y = msg3.poses.at(0).orientation.y;
 aurora1_ori_z = msg3.poses.at(0).orientation.z;
 aurora2_ori_x = msg3.poses.at(1).orientation.x;
 aurora2_ori_y = msg3.poses.at(1).orientation.y;
 aurora2_ori_z = msg3.poses.at(1).orientation.z;

top_x = printt(aurora1_x);
top_y = printt(aurora1_y);
top_z = printt(aurora1_z);

top_ori_x = printt(aurora1_ori_x);
top_ori_y = printt(aurora1_ori_y);
top_ori_z = printt(aurora1_ori_z);

bot_x = printt(aurora2_x);
bot_y = printt(aurora2_y);
bot_z = printt(aurora2_z);

bot_ori_x = printt(aurora2_ori_x);
bot_ori_y = printt(aurora2_ori_y);
bot_ori_z = printt(aurora2_ori_z);

// ROS_INFO("1: [%f] 1: [%f] 1: [%f] 1: [%f] 1: [%f] 1: [%f] 1: [%f] 1: [%f] 1: [%f] 1: [%f] 1: [%f] 1: [%f]", 
//aurora1_x, aurora1_y ,aurora1_z ,aurora1_ori_x, aurora1_ori_y, aurora1_ori_z, aurora2_x, aurora2_y, aurora2_z, aurora2_ori_x, aurora2_ori_y, aurora2_ori_z);


}



float printt(float b){
//ROS_INFO("here");
//cout<< b<<endl;
return b;
}




int main(int argc, char **argv)
{
float dtenz1,dtenz2,dteny1,dteny2,dtenx, dirr;

int check_x = 0;
int check_y = 0;
int check_z = 0;

  ros::init(argc, argv, "control");
  ros::NodeHandle n, de_t;
  ros::Rate r(100);
  ros::NodeHandle position, node;
  std_msgs::Float32 msg;
  tension_m::tension msg2;
  geometry_msgs::PoseArray msg3;
  geometry_msgs::WrenchStamped nano17;
////////////////////////////////////////////


ros::Publisher target_tx1_pub= de_t.advertise<std_msgs::Float32>("target_tx1", 100);
ros::Publisher target_ty1_pub= de_t.advertise<std_msgs::Float32>("target_ty1", 100);
ros::Publisher target_tz1_pub= de_t.advertise<std_msgs::Float32>("target_tz1", 100);

ros::Publisher desired_tz1_pub= de_t.advertise<std_msgs::Float32>("desired_tz1", 100);
ros::Publisher desired_tz2_pub= de_t.advertise<std_msgs::Float32>("desired_tz2", 100);
ros::Publisher desired_ty1_pub= de_t.advertise<std_msgs::Float32>("desired_ty1", 100);
ros::Publisher desired_ty2_pub= de_t.advertise<std_msgs::Float32>("desired_ty2", 100);
ros::Publisher desired_dis_pub= de_t.advertise<std_msgs::Float32>("desired_dis", 100);
ros::Publisher desired_dir_pub= de_t.advertise<std_msgs::Float32>("desired_dir", 100);

  ros::Subscriber sub1 = n.subscribe("/tension", 1000, tension1);
  ros::Subscriber sub2 = n.subscribe("/aurora", 1000, aurora);
  ros::Subscriber sub3 = n.subscribe("/finger1/nano17ft", 1000, nano17re); 
  ros::Rate loop_rate(100);

int tnum = 0;

float dteny1_pre = 1,dteny2_pre = 1,dtenz1_pre = 1,dtenz2_pre = 1; 

int hh = 0;
while(ros::ok()){

//ROS_INFO("%f %f %f %f ",tension_v1,tension_v2,tension_v3,tension_v4);

ROS_INFO("%f %f %f %f %f %f", s_fx, s_fy , s_fz, s_mx, s_my, s_mz);
//ROS_INFO(" %f %f %f %f %f %f %f %f %f %f %f %f", top_x, top_y, top_z, top_ori_x,  top_ori_y,  top_ori_z, bot_x, bot_y, bot_z, bot_ori_x,  bot_ori_y, bot_ori_z);

msg.data = 0.00;   //tension1
desired_ty1_pub.publish(msg);

msg.data = 0.00;   //tension2
desired_ty2_pub.publish(msg);

msg.data = 0.00;   //tension3
desired_tz1_pub.publish(msg);

msg.data = 1.00;   // tension4
desired_tz2_pub.publish(msg);


msg.data = 50.0;
desired_dis_pub.publish(msg);

msg.data = 2;
desired_dir_pub.publish(msg);


// direction need a algorithm. like if 
// if desired position of translation is zero, then direction value became 3;;
// 1 is negative backward
// 2  is forward


        ros::spinOnce();
       // r.sleep();
hh++;
    }

  return 0;
}




















