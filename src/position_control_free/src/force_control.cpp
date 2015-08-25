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
float aurora1_x, aurora1_y, aurora1_z, aurora2_x, aurora2_y , aurora2_z, aurora1_ori_x, aurora1_ori_y, aurora1_ori_z, aurora2_ori_x, aurora2_ori_y, aurora2_ori_z,aurora2_ori_w,aurora1_ori_w;
float  top_x, top_y, top_z, top_ori_x, top_ori_y, top_ori_z, top_ori_w, bot_ori_x, bot_ori_y, bot_ori_w, bot_ori_z, bot_x, bot_y, bot_z;  
float nano_fx, nano_fz, nano_fy, nano_mx, nano_my, nano_mz, s_fx, s_fy, s_fz, s_mx, s_my, s_mz;    
float contact_position_x[13] = {-2.015,   -1.762, -0.914, 1.165-0.9,  1.696,  1.73+1.1, 4.234-0.5,   4.687, 5.349, 5.057, 5.367, 5.495, 5.181};
float contact_position_y[13] = {-8.362,  -6.079,  -4.139, -2.691, -0.812,  1.143-0.5-0.4, 1.255,    2.5, 3.139, 3.624, 3.353, 2.848, 3.07};
float contact_position_z[13] = { 13.179,  13.175, 13.428-0.4, 13.5-0.5, 12.695,  11.873, 11.4, 10.681, 9.653, 9.822, 10.12, 9.502, 9.237};


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
 aurora1_ori_w = msg3.poses.at(0).orientation.w;
 aurora2_ori_x = msg3.poses.at(1).orientation.x;
 aurora2_ori_y = msg3.poses.at(1).orientation.y;
 aurora2_ori_z = msg3.poses.at(1).orientation.z;
 aurora2_ori_w = msg3.poses.at(1).orientation.w;

top_x = printt(aurora1_x);
top_y = printt(aurora1_y);
top_z = printt(aurora1_z);

top_ori_x = printt(aurora1_ori_x);
top_ori_y = printt(aurora1_ori_y);
top_ori_z = printt(aurora1_ori_z);
top_ori_w = printt(aurora1_ori_w);
bot_x = printt(aurora2_x);
bot_y = printt(aurora2_y);
bot_z = printt(aurora2_z);

bot_ori_x = printt(aurora2_ori_x);
bot_ori_y = printt(aurora2_ori_y);
bot_ori_z = printt(aurora2_ori_z);
bot_ori_w = printt(aurora2_ori_w);





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
  ros::NodeHandle n, de_t, m;
  ros::Rate r(100);
ros::Rate a(5);
  ros::NodeHandle position, node;
  std_msgs::Float32 msg;
  tension_m::tension msg2;
  geometry_msgs::PoseArray msg3;
  geometry_msgs::WrenchStamped nano17;

ros::Publisher marker_pub = m.advertise<visualization_msgs::Marker>("target_marker", 5);
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
////////////////////////////////////////////

visualization_msgs::Marker Target_point;
Target_point.header.frame_id = "/aurora";
Target_point.header.stamp=ros::Time::now();
Target_point.ns= "control";
Target_point.action =visualization_msgs::Marker::ADD;
Target_point.type = visualization_msgs::Marker::SPHERE;

	Target_point.scale.x =.2;
	Target_point.scale.y =.2;
	Target_point.scale.z =.2;
   Target_point.pose.orientation.x = 0.0;
   Target_point.pose.orientation.y = 0.0;
   Target_point.pose.orientation.z = 0.0;
   Target_point.pose.orientation.w = 1.0;

Target_point.color.g = 0.0;
Target_point.color.b = 1.0;
Target_point.color.r = 1.0;
Target_point.color.a = 1.0;

	Target_point.id = 0;

  Target_point.pose.position.x = contact_position_x[0];
  Target_point.pose.position.y  = contact_position_y[0];
  Target_point.pose.position.z  = contact_position_z[0];

   marker_pub.publish(Target_point);

	a.sleep();

	Target_point.id = 0;

  Target_point.pose.position.x = contact_position_x[0];
  Target_point.pose.position.y  = contact_position_y[0];
  Target_point.pose.position.z  = contact_position_z[0];

   marker_pub.publish(Target_point);

	a.sleep();
	Target_point.id = 0;

  Target_point.pose.position.x = contact_position_x[0];
  Target_point.pose.position.y  = contact_position_y[0];
  Target_point.pose.position.z  = contact_position_z[0];

   marker_pub.publish(Target_point);

	a.sleep();
	Target_point.id = 0;

  Target_point.pose.position.x = contact_position_x[0];
  Target_point.pose.position.y  = contact_position_y[0];
  Target_point.pose.position.z  = contact_position_z[0];

   marker_pub.publish(Target_point);

	a.sleep();

	Target_point.id = 1;

  Target_point.pose.position.x = contact_position_x[1];
  Target_point.pose.position.y  = contact_position_y[1];
  Target_point.pose.position.z  = contact_position_z[1];

   marker_pub.publish(Target_point);

	a.sleep();
	Target_point.id = 1;

  Target_point.pose.position.x = contact_position_x[1];
  Target_point.pose.position.y  = contact_position_y[1];
  Target_point.pose.position.z  = contact_position_z[1];

   marker_pub.publish(Target_point);

	a.sleep();
	Target_point.id = 1;

  Target_point.pose.position.x = contact_position_x[1];
  Target_point.pose.position.y  = contact_position_y[1];
  Target_point.pose.position.z  = contact_position_z[1];

   marker_pub.publish(Target_point);

	a.sleep();
	Target_point.id = 1;

  Target_point.pose.position.x = contact_position_x[1];
  Target_point.pose.position.y  = contact_position_y[1];
  Target_point.pose.position.z  = contact_position_z[1];

   marker_pub.publish(Target_point);




for(int h = 2; h <13 ;h++){
//int h = 1;
	Target_point.id = h;

  Target_point.pose.position.x = contact_position_x[h];
  Target_point.pose.position.y  = contact_position_y[h];
  Target_point.pose.position.z  = contact_position_z[h];

   marker_pub.publish(Target_point);

	a.sleep();
}

int tnum = 0;

float dteny1_pre = 1,dteny2_pre = 1,dtenz1_pre = 1,dtenz2_pre = 1; 
int hh = 0, ii = 0;
int loop_check = 0;
float top_ori_x_ini,top_ori_y_ini,top_ori_z_ini,top_ori_w_ini;

while(ros::ok()){

//ROS_INFO("%f %f %f %f ",tension_v1,tension_v2,tension_v3,tension_v4);

//ROS_INFO("%f %f %f %f %f %f", s_fx, s_fy , s_fz, s_mx, s_my, s_mz);
//ROS_INFO(" %f %f %f %f %f %f %f %f %f %f %f %f", top_x, top_y, top_z, top_ori_x,  top_ori_y,  top_ori_z, bot_x, bot_y, bot_z, bot_ori_x,  bot_ori_y, bot_ori_z);

/*
float theta_x = (atan2(2*(top_ori_x*top_ori_y+top_ori_z*top_ori_w), (top_ori_x*top_ori_x-(top_ori_y*top_ori_y)-(top_ori_z*top_ori_z)+top_ori_w*top_ori_w))*180/3.14 );
float theta_y = (asinl(-2*(top_ori_x*top_ori_z-top_ori_y*top_ori_w)/((top_ori_x*top_ori_x+top_ori_y*top_ori_y+top_ori_z*top_ori_z+top_ori_w*top_ori_w)))*180/3.14 );
float theta_z = (atan2(2*(top_ori_y*top_ori_z+top_ori_x*top_ori_w), ((-(top_ori_x*top_ori_x)-(top_ori_y*top_ori_y)+top_ori_z*top_ori_z+top_ori_w*top_ori_w)))*180/3.14 );
*//*
float theta_x = (atan2(2*(top_ori_w*top_ori_x+top_ori_y*top_ori_z), 1-2*(top_ori_x*top_ori_x+(top_ori_y*top_ori_y)))*180/3.14 )-170.619675;
float theta_y = ((asin(-2*(top_ori_x*top_ori_z-top_ori_y*top_ori_w)/((top_ori_x*top_ori_x+top_ori_y*top_ori_y+top_ori_z*top_ori_z+top_ori_w*top_ori_w)))*180/3.14 ))-49.999321;
float theta_z = (atan2(2*(top_ori_w*top_ori_z+top_ori_x*top_ori_y), 1-2*(top_ori_y*top_ori_y+(top_ori_z*top_ori_z)))*180/3.14 );
*/
float heading, attitude, bank;

	double test = top_ori_x/2*top_ori_y/2 + top_ori_z/2*top_ori_w/2;
	if (test > 0.499) { // singularity at north pole
		heading = 2 * atan2(top_ori_x/2,top_ori_w/2);
		attitude = 3.14/2;
		bank = 0;
	
	}
	if (test < -0.499) { // singularity at south pole
		heading = -2 * atan2(top_ori_x/2,top_ori_w/2);
		attitude = - 3.14/2;
		bank = 0;
		
	}
    double sqx = top_ori_x/2*top_ori_x/2;
    double sqy = top_ori_y/2*top_ori_y/2;
    double sqz = top_ori_z/2*top_ori_z/2;


        heading = atan2(2*top_ori_y/2*top_ori_w/2-2*top_ori_x/2*top_ori_z/2 , 1 - 2*sqy - 2*sqz);
	attitude = asin(2*test);
	bank = atan2(2*top_ori_x/2*top_ori_w/2-2*top_ori_y/2*top_ori_z/2 , 1 - 2*sqx - 2*sqz);



float theta_x = (atan( 2*(top_ori_w*top_ori_x+top_ori_y*top_ori_z)/(1-2*(top_ori_x*top_ori_x+top_ori_y*top_ori_y))  )*180/3.14 )*3;
float theta_y = ((asin(-2*(top_ori_x*top_ori_z-top_ori_y*top_ori_w)/((top_ori_x*top_ori_x+top_ori_y*top_ori_y+top_ori_z*top_ori_z+top_ori_w*top_ori_w)))*180/3.14 ))*2;
float theta_z = (atan2(2*(top_ori_w*top_ori_z+top_ori_x*top_ori_y), 1-2*(top_ori_y*top_ori_y+(top_ori_z*top_ori_z)))*180/3.14 );

float theta_x2 = (atan( 2*(bot_ori_w*bot_ori_x+bot_ori_y*bot_ori_z)/(1-2*(bot_ori_x*bot_ori_x+bot_ori_y*bot_ori_y))  )*180/3.14 )*3;
float theta_y2 = ((asin(-2*(bot_ori_x*bot_ori_z-bot_ori_y*bot_ori_w)/((bot_ori_x*bot_ori_x+bot_ori_y*bot_ori_y+bot_ori_z*bot_ori_z+bot_ori_w*bot_ori_w)))*180/3.14 ))*2;
float theta_z2 = (atan2(2*(bot_ori_w*bot_ori_z+bot_ori_x*bot_ori_y), 1-2*(bot_ori_y*bot_ori_y+(bot_ori_z*bot_ori_z)))*180/3.14 );

float the_x = top_ori_x*180/3.14;





ROS_INFO("after  %f %f  %f before %f %f  %f test %f", heading*180/3.14+139, attitude*180/3.14, bank*180/3.14+135,heading*180/3.14, attitude*180/3.14, bank*180/3.14, test);


msg.data = 0.00;   //tension1
desired_ty1_pub.publish(msg);

msg.data = 0.00;   //tension2
desired_ty2_pub.publish(msg);

msg.data = 0.00;   //tension3
desired_tz1_pub.publish(msg);

msg.data = 1.00;   // tension4
desired_tz2_pub.publish(msg);


msg.data = 20.0;
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





















