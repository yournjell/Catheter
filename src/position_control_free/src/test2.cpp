
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <std_msgs/Float32.h>
#include <iostream>
#include <sstream>
#include <math.h>
//#include <mms.h>

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
float dtenz1,dtenz2,dteny1,dteny2,dtenx, dirr;

int check_x = 1;
int check_y = 1;
int check_z = 1;
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



float mm_px,mm_py,mm_pz;

float j_x= 0.0338;
float j_y= 0.0338;
float j_z= 0.0338;
float tension_v1pre = 0;
float tension_v2pre = 0;
float tension_v3pre = 0;
float tension_v4pre = 0;
float pre_x = 0;
float pre_y = 0;
float pre_z = 0;


float target_x, target_y, target_z;

float target_position_x[8] = {294, 365, 356, 300 ,330, 350, 300, 280};
float target_position_y[8] = {506, 250, 395, 350 ,300, 400, 395, 270};
float target_position_z[8] = {341, 273, 135, 300 ,380, 350, 300, 200};
int tnum = 0;
while(ros::ok()){



//// position in mm
      mm_px = abs(640-(side_f_1b))/3.5; // position_side_final[i][3] and position_side_final[i][
 if((mm_px)<5)  {mm_px = abs(side_f_3b-478)/4.0; //position_side_final[i][3] and position_side_final[i][1]
}    
       mm_py = -((side_f_0b)-416)/4.0;
       mm_pz = -((side_f_2b-282))/3.5;//((position_side_final[i][2]/4.08)-(457/4.08))*0.1;


float pixel_px,pixel_py,pixel_pz;
//// position in pixel
      pixel_px = abs(640-(side_f_1b))*1.108; // position_side_final[i][3] and position_side_final[i][
 
if((pixel_px)<5)  {pixel_px = abs(side_f_3b-478); //position_side_final[i][3] and position_side_final[i][1]
}    
       pixel_py = -((side_f_0b)-416);
       pixel_pz = -((side_f_2b-282));//((position_side_final[i][2]/4.08)-(457/4.08))*0.1;


////// jacobian/////


if ((check_x==1)&&(check_y==1)&&(check_z==1)){


dteny2 = tension_v2;
dteny1 = tension_v1;

dtenz2 = tension_v4;
dtenz1 = tension_v3;
dtenx = 000;
dirr = 0;
cout<<"finsk"<<endl;

check_x =0;
check_y =0;
check_z =0;

target_x = abs(target_position_x[tnum]-640)/3.5;
target_y =-(target_position_y[tnum]-416)/4.0;
target_z = -(target_position_z[tnum]-282)/3.5;

tnum = tnum+1;

if (tnum == 8){

break;
}


}

else{


	if(abs(abs(target_y) - abs(mm_py))<=3){
	dteny2 = tension_v4;
	dteny1 = tension_v3;
	check_y = 1;
	
	cout<<"yyyyyyyyyy"<<endl;
	}
	else if (target_y>0){

	   dteny1 = (0.09*(target_y - mm_py))+tension_v3pre;
		
	   dteny2 = 0.00;
 		
		if (dteny1 <0){

		dteny2 = 1.00+tension_v4pre;
		dteny1 = 0.00;


			}
	}

	else if (target_y<0){

	   dteny2 = (0.09*(abs(target_y) - abs(mm_py) ))+tension_v4pre;
	
	   dteny1 = 0.00;
		if (dteny2 <0){
			dteny1 =1.00+tension_v3pre;
		dteny2 = 0.00;


		}

	}


		if(abs(abs(target_z) - abs(mm_pz))<=3){

		dtenz2 = tension_v4;
		dtenz1 = tension_v3;

		cout<<"zzzzz"<<endl;
		check_z = 1;
		}


		else if (target_z>0){

		   dtenz1 = (0.09*(target_z - mm_pz))+tension_v1pre;
		dtenz2 = 0.00;
		if (dtenz1 <0){
			dtenz2 = 1.00+tension_v2pre;
		dtenz1 = 0.00;


		}
		   
		}
		else if (target_z<0){

		   dtenz2 = (0.09*(abs(target_z) - abs(mm_pz)))+tension_v2pre;
		
		 dtenz1 = 0.00;

		if (dtenz2 <0){
		dtenz1 = 1.00;
		dtenz2 = 0.00;}

		  
		}
		else if (target_z==0){

		   dtenz2 = 0;
		   dtenz1 = 0;
		}


		

			if(abs(abs(target_x) - abs(mm_px))<=3){
			dtenx = 000;
			dirr = 0;
			cout<<"xcxxx"<<endl;
			check_x = 1;
			}

			else if ((target_x - mm_px)>0){
			dtenx = 100;
			dirr = 1;

			}

			else if((target_x - mm_px)<0){
			dtenx = 100;
			dirr = 2;
			}
			else if (target_z==0){

			   dtenz2 = 0;
			   dtenz1 = 0;
			}
			


}




cout << mm_px << " y "<< mm_py << " z " << mm_pz<< endl;
cout << target_x << " targety "<< target_y << " target z " << target_z<<endl;
cout << dteny1 << "  " << dteny2 << "  "<< dtenz1<< "  "<<dtenz2 <<"  " <<tnum <<endl; 

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

pre_x = mm_px;
pre_y = mm_py;
pre_z = mm_pz;

tension_v1pre = tension_v1;
tension_v2pre = tension_v2;
tension_v3pre = tension_v3;
tension_v4pre = tension_v4;

    }

  return 0;
}





















