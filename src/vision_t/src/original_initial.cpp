 #include <ros/ros.h>
 #include <visualization_msgs/Marker.h>
 #include <cstdlib>
#include <unistd.h>

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

unsigned int microseconds = 5000;
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

int check_x = 0;
int check_y = 0;
int check_z = 0;

  ros::init(argc, argv, "control");
  ros::NodeHandle n, de_t;
  std_msgs::Float32 msg;
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("target_marker", 10);
  ros::Rate r(5);
  ros::NodeHandle position;

////////////////////////////////////////////////////////////////
visualization_msgs::Marker Target_point;
Target_point.header.frame_id = "/catheter_shape";
Target_point.header.stamp=ros::Time::now();
Target_point.ns= "control";
Target_point.action =visualization_msgs::Marker::ADD;
Target_point.pose.orientation.w= 1.0;

	Target_point.type = visualization_msgs::Marker::SPHERE;




//float target_position_x[23] = {255, 230, 230 ,230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230,    //313 , 299 , 264 , 229 , 215 , 229 , 264 , 299 , 313 };
//float target_position_y[23] = {367, 367, 417 ,467, 437, 367, 296, 267, 296, 367, 437, 467, 417, 367,    ///356 , 359, 365, 371, 374, 371, 365, 359, 356};
//float target_position_z[23] = {330, 330, 330 ,330, 421, 460, 421, 330, 238, 200, 238, 330, 330, 330,    ///291 , 347, 371, 347, 291, 234, 211, 234, 291};



//float target_position_x[6] = {330, 400, 433, 387, 311, 280};
//float target_position_y[6] = {569, 553, 470, 420, 435, 503};
//float target_position_z[6] = {365, 390, 453, 475, 450, 400};

///// REcord 1 ////////
//float target_position_x[8] = {231, 260, 322, 384, 417, 397, 329, 262};
//float target_position_z[8] = {227, 189, 167, 185, 230, 277, 295, 276};

//float target_position_y[8] = {558, 615, 617, 564, 493, 443, 445, 491};
//float target_position_xtop[8] = {94, 137, 218, 288, 297, 256, 182, 115};



//for(int h = 0; h<8; h++){


//target_position_xtop[h] = target_position_xtop[h]-50;
//target_position_x[h] = target_position_x[h]-50;

//target_position_z[h] = target_position_z[h]+80;
//target_position_y[h] = target_position_y[h]-50-140;

//}
//////////////////////////////////

//float target_position_x[27] = {255, 230, 230 ,230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 270, 300, 350, 430, 313, 299, 264, 229, 215, 229, 264, 299, 313 };
//float target_position_z[27] = {330, 330, 330 ,330, 421, 460, 421, 330, 238, 200, 238, 330, 330, 330, 320, 310, 300, 295, 291, 347, 371, 347, 291, 234, 211, 234, 291};

//float target_position_xtop[27] = {95, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 110, 140, 190, 270, 153, 139, 104,  69, 54, 69, 104, 139, 153};
//float target_position_y[27] = {367, 367, 417 ,467, 437, 367, 296, 267, 296, 367, 437, 467, 417, 367, 300, 250, 230, 190, 356, 359, 365, 371, 374, 371, 365, 359, 356};



///// REcord 2 ////////

//float target_position_x[21] = {230, 230, 230, 230, 230, 230, 230, 230, 230,  300, 350, 430, 313, 299, 264, 229, 215, 229, 264, 299, 313 };
//float target_position_z[21] = {421, 460, 421, 330, 238, 200, 238, 330, 330,  310, 300, 295, 291, 347, 371, 347, 291, 234, 211, 234, 291};

//float target_position_xtop[21] = {70, 70, 70, 70, 70, 70, 70, 70, 70,  140, 190, 270, 153, 139, 104,  69, 54, 69, 104, 139, 153};
//float target_position_y[21] = {437, 367, 296, 267, 296, 367, 437, 467,  300, 250, 230, 190, 356, 359, 365, 371, 374, 371, 365, 359, 356};


//int xg = 180;
//int yg = 160;
//int zg = 40;

//for(int h = 12; h<21; h++){

//target_position_x[h] = target_position_x[h]+xg;
//target_position_xtop[h] = target_position_xtop[h]+xg;
//target_position_y[h] = target_position_y[h]-yg;

//}

//for(int h = 0; h<21; h++){
//target_position_z[h] = target_position_z[h]-100;

//}


///// REcord 3 ////////

//////////////////////////////////

float target_position_x[18] = { 313, 299, 264, 229, 215, 229, 264, 299, 313, 	215, 229, 264, 299, 313, 	299, 264, 229,	215   };
float target_position_z[18] = { 291, 347, 371, 347, 291, 234, 211, 234, 291, 	291, 234, 211, 234, 291,	 347, 371, 347,  291    };

float target_position_xtop[18] = {153, 139, 104,  69, 54, 69, 104, 139, 153, 	54, 69, 104, 139, 153, 		 139, 104,  69,   54    };
float target_position_y[18] = {356, 359, 365, 371, 374, 371, 365, 359,  356, 	374, 371, 365, 359, 356,	 359, 365, 371,	 374   };
int xg = 0;
int yg = 100;
int zg = 0;

for(int h = 0; h<9; h++){


target_position_x[h] = target_position_x[h]+xg-20;
target_position_xtop[h] = target_position_xtop[h]+xg-20+50;
target_position_y[h] = target_position_y[h]-yg;

}


for(int h = 0; h<9; h++){


target_position_z[h] = target_position_z[h]-60-50;

}





for(int h = 9; h<18; h++){


target_position_x[h] = (target_position_x[h]+xg+10)*1.3;
target_position_xtop[h] = (target_position_xtop[h]+xg+10)*1.3;
target_position_y[h] = (target_position_y[h]-yg-120)*1.3;
target_position_z[h] = (target_position_z[h]-60-60)*1.3;

}




//////////////////////////////////

//float target_position_x[6] = {203, 227, 308, 356, 325, 253};
//float target_position_y[6] = {405, 458, 528, 506, 446, 397};
//float target_position_z[6] = {337, 271, 264, 339, 397, 406};



	Target_point.scale.x =1;
	Target_point.scale.y =1;
	Target_point.scale.z =1;



Target_point.color.b = 0.0;
Target_point.color.r = 1.0;
Target_point.color.a = 1.0;

	Target_point.id = 0;

  Target_point.pose.position.x = (abs(640-(target_position_x[0]))/3.5)/10; //position_side_final[i][3] and position_side_final[i][
       if((abs(640-(target_position_x[0]))/3.5)/10<5/10)  {  Target_point.pose.position.x = (abs(target_position_x[0]-477)/4.0)/5; }    
  Target_point.pose.position.y  = -(((target_position_y[0])-410)/4.0)/10 ; 
  Target_point.pose.position.z  = -(((target_position_z[0]-173))/3.5)/10;//((position_side_final[i][2]/4.08)-(457/4.08))*0.1;

   marker_pub.publish(Target_point);

	r.sleep();

Target_point.color.b = 0.0;
Target_point.color.r = 1.0;
Target_point.color.a = 1.0;

	Target_point.id = 1;

  Target_point.pose.position.x = (abs(640-(target_position_x[1]))/3.5)/10; //position_side_final[i][3] and position_side_final[i][
       if((abs(640-(target_position_x[1]))/3.5)/10<5/10)  {  Target_point.pose.position.x = (abs(target_position_x[1]-478)/4.0)/5; }    
  Target_point.pose.position.y  = -(((target_position_y[1])-410)/4.0)/10 ; 
  Target_point.pose.position.z  = -(((target_position_z[1]-173))/3.5)/10;//((position_side_final[i][2]/4.08)-(457/4.08))*0.1;

   marker_pub.publish(Target_point);

	r.sleep();




Target_point.color.b = 0.0;
Target_point.color.r = 1.0;
Target_point.color.a = 1.0;


for(int h = 0; h <18 ;h++){

	Target_point.id = h+5;

  Target_point.pose.position.x = (abs(640-(target_position_x[h]))/3.5)/10; //position_side_final[i][3] and position_side_final[i][
    //   if((abs(640-(target_position_x[h]))/3.5)/10<5/10)  {  Target_point.pose.position.x = (abs(target_position_x[h]-478)/4.0)/5; }    
  Target_point.pose.position.y  = -(((target_position_y[h])-410)/4)/10 ; 
  Target_point.pose.position.z  = -(((target_position_z[h]-173))/3.5)/10;//((position_side_final[i][2]/4.08)-(457/4.08))*0.1;

   marker_pub.publish(Target_point);

	r.sleep();
}



////////////////////////////////////////////


  ros::Subscriber sub1 = n.subscribe("tension11", 100, tension1);
  ros::Subscriber sub2 = n.subscribe("tension21", 100, tension2);
  ros::Subscriber sub3 = n.subscribe("tension31", 100, tension3);
  ros::Subscriber sub4 = n.subscribe("tension41", 100, tension4);

  ros::Subscriber sub5 = n.subscribe("shaft_x", 100, shaft_x);
  ros::Subscriber sub6 = n.subscribe("shaft_y", 100, shaft_y);
  ros::Subscriber sub7 = n.subscribe("shaft_z", 100, shaft_z);

  ros::Subscriber sub8 = n.subscribe("position_x", 100, side_f_p1);
  ros::Subscriber sub9 = n.subscribe("position_y", 100, side_f_p2);
  ros::Subscriber sub10 = n.subscribe("position_z", 100, side_f_p3);
 

ros::Publisher target_tx1_pub= de_t.advertise<std_msgs::Float32>("target_tx1", 100);
ros::Publisher target_ty1_pub= de_t.advertise<std_msgs::Float32>("target_ty1", 100);
ros::Publisher target_tz1_pub= de_t.advertise<std_msgs::Float32>("target_tz1", 100);


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

//float target_position_x[8] = {294, 365, 356, 300 ,330, 350, 300, 280};
//float target_position_y[8] = {506, 250, 395, 350 ,300, 320, 360, 450};
//float target_position_z[8] = {341, 273, 135, 200 ,250, 300, 350, 350};
int tnum = 0;

target_x = abs(target_position_x[0]-640)/3.5;
target_y =-(target_position_y[0]-410)/4.0;
target_z = -(target_position_z[0]-173)/3.5;



float dteny1_pre = 1,dteny2_pre = 1,dtenz1_pre = 1,dtenz2_pre = 1; 

while(ros::ok()){



//// position in mm
      mm_px = side_f_0b; // position_side_final[i][3] and position_side_final[i][
      mm_py = side_f_1b;
      mm_pz = side_f_2b;//((position_side_final[i][2]/4.08)-(457/4.08))*0.1;


////// jacobian/////


msg.data = target_x;
target_tx1_pub.publish(msg);
msg.data = target_y;
target_ty1_pub.publish(msg);
msg.data = target_z;
target_tz1_pub.publish(msg);



if((tension_v1 == 0) && (tension_v2 == 0) && (tension_v3 == 0) && (tension_v4 == 0) ){



//cout << "no tension "<<endl;

}
else if( (abs(tension_v1-dteny1_pre)>0.07)&&(abs(tension_v2-dteny2_pre)>0.07)&&(abs(tension_v3-dtenz1_pre)>0.07)&&(abs(tension_v4-dtenz2_pre)>0.07) ){

dteny1 = dteny1_pre;
dteny2 = dteny2_pre;
dtenz1 = dtenz1_pre;
dtenz2 = dtenz2_pre;


			if(abs((target_x) - (mm_px))<=3){
			dtenx = 000;
			dirr = 0;
			
			check_x = 1;
			}

			else if ((target_x - mm_px)>0){
			dtenx = 100;
			dirr = 1;
			check_x = 0;
			}

			else if((target_x - mm_px)<0){
			dtenx = 100;
			dirr = 2;	
			check_x = 0;
			}
		
}


else if( (mm_py==0)&&(mm_px==0)&&(mm_pz==0) ){

dteny1 = dteny1_pre;
dteny2 = dteny2_pre;
dtenz1 = dtenz1_pre;
dtenz2 = dtenz2_pre;
dtenx = 000;
dirr = 0;
		
}




else if ((check_x==1)&&(check_y==1)&&(check_z==1)){



usleep(microseconds);
Target_point.color.b = 1.0;
Target_point.color.r = 0.0;
Target_point.color.a = 1.0;

	Target_point.id = tnum+5;

  Target_point.pose.position.x = (abs(640-(target_position_x[tnum]))/3.5)/10; //position_side_final[i][3] and position_side_final[i][
  //     if((abs(640-(target_position_x[tnum]))/3.5)/10<5/10)  {  Target_point.pose.position.x = (abs(target_position_x[tnum]-478)/4.0)/5; }    
  Target_point.pose.position.y  = -(((target_position_y[tnum])-410)/4.0)/10 ; 
  Target_point.pose.position.z  = -(((target_position_z[tnum]-173))/3.5)/10;//((position_side_final[i][2]/4.08)-(457/4.08))*0.1;

   marker_pub.publish(Target_point);

	r.sleep();

dteny2 = tension_v2;
dteny1 = tension_v1;

dtenz2 = tension_v4;
dtenz1 = tension_v3;

dtenx = 000;
dirr = 0;

check_x =0;
check_y =0;
check_z =0;

tnum = tnum+1;

target_x = abs(target_position_x[tnum]-640)/3.5;
target_y =-(target_position_y[tnum]-410)/4.0;
target_z = -(target_position_z[tnum]-173)/3.5;




if (tnum == 18){

break;
}


}

else{


		if(abs(abs(target_y) - abs(mm_py))<=3){
		dteny2 = 0.00;
		dteny1 = 0.00;
		check_y = 1;
		}




		else if (target_y>0){
		check_y = 0;

		dteny2 = 0.00;
			
		if(mm_py>0){
			if ((abs(mm_py-target_y)<2)&&((mm_pz/target_z)>0)){dteny1 = tension_v1;}
			else if(mm_py>target_y){  dteny1 = (0.01*-(mm_py - target_y))+tension_v1; }
			else if(mm_py<target_y){  dteny1 = (0.01*(target_y - mm_py))+tension_v1; }
			
			if(dteny1 < 0){ dteny1 = 0.06;}
			
			if((dteny1 < 0.07 )&&(tension_v1 < 0.10)){ dteny2 =  (0.01*abs(target_y - mm_py));//(0.01*abs(mm_py- target_y)) ;
								   dteny1 = 0.00; }

			}
	

		else if(mm_py<0){

			if (abs(mm_py-target_y)<2){dteny1 = tension_v1;}
			else {  dteny1 = (0.01*abs(mm_py)); }
			dteny2 = 0.00;

			     }
		 }
  




		else if (target_y<0){
		check_y = 0;
		dteny1 = 0.00;


				if(mm_py<0){

				if ((abs(mm_py-target_y)<2)&&((mm_py/target_y)>0)){dteny2 = tension_v2;}
				else if(abs(mm_py)>abs(target_y)){  dteny2 = (0.01*-(abs(mm_py) - abs(target_y)  ))+tension_v2; }
				else if(abs(mm_py)<abs(target_y)){  dteny2 = (0.01*(abs(target_y) - abs(mm_py)  ))+tension_v2; }
	
				if(dteny2 < 0){ dteny2 = 0.06;}
				if((dteny2<0.07)&&(tension_v2 < 0.1)){ dteny1 = (0.01*abs(mm_py-target_y)) ;
								       dteny2 = 0.00; }

			
				}

				else if(mm_py>0){

				if (abs(mm_py-target_y)<2){dteny2 = tension_v2;}
				else {  dteny2 = (0.01*abs(mm_py)); }

					dteny1 = 0.00;

				}
			}

				else if (target_y==0){

				   check_y = 0;
				   dteny2 = 0;
				   dteny1 = 0;
				}



		if(abs(abs(target_z) - abs(mm_pz))<=3){

		dtenz2 = 0.00;
		dtenz1 = 0.00;

		check_z = 1;
		}

			else if (target_z>0){

			check_z = 0;

			dtenz2 = 0.00;

				if(mm_pz>0){
			
				if ((abs(mm_pz-target_z)<2)&&( (mm_pz/target_z)>0 ) ){dtenz1 = tension_v3;}
				else if(mm_pz>target_z){  dtenz1 = (0.01*-(mm_pz - target_z))+tension_v3; }
				else if(mm_pz<target_z){  dtenz1 = (0.01*(target_z - mm_pz))+tension_v3; }

				if(dtenz1 < 0){ dtenz1 = 0.06;}
			
				if((dtenz1 < 0.07 )&&(tension_v3 < 0.10)){ dtenz2 = (0.01*abs(mm_pz-target_z)) ;
								   dtenz1 = 0.00; }

					}
			

				else if(mm_pz<0){

				if (abs(mm_pz-target_z)<2){dtenz1 = tension_v3;}
				else {  dtenz1 = (0.01*abs(mm_pz)) ;
					dtenz2 = 0.00; }
				}	

			}
   


				else if (target_z<0){
				dtenz1 = 0.00;
				check_z = 0;


						if(mm_pz<0){

						if ((abs(mm_pz-target_z)<2)&&((mm_pz/target_z)>0)){dtenz2 = tension_v4;}
						else if(abs(mm_pz)>abs(target_z)){  dtenz2 = (0.01*-(abs(mm_pz) -abs(target_z)  ))+tension_v4; }
						else if(abs(mm_pz)<abs(target_z)){  dtenz2 = (0.01*(abs(target_z) - abs(mm_pz) ))+tension_v4; }
	
						if(dtenz2 < 0){ dtenz2 = 0.06;}
			
						if((dtenz2 < 0.07 )&&(tension_v4 < 0.10)){ dtenz1= (0.01*abs(mm_pz-target_z));
									 		  dtenz2 = 0.00; }

							}
				
						else if(mm_pz>0){


						if (abs(mm_pz-target_z)<2){dtenz2 = tension_v4;}
						else {  dtenz2 = 0.01*(abs(mm_pz)) ;
							dtenz1 = 0.00; }

							}
					}

					else if (target_z==0){

					   check_z = 0;
					   dtenz2 = 0;
					   dtenz1 = 0;
					}


		

			if(abs((target_x) - (mm_px))<=3){
			dtenx = 000;
			dirr = 0;
			
			check_x = 1;
			}

			else if ((target_x - mm_px)>0){
			dtenx = 100;
			dirr = 1;
			check_x = 0;
			}

			else if((target_x - mm_px)<0){
			dtenx = 100;
			dirr = 2;	
			check_x = 0;
			}
		


		}

dteny1_pre = dteny1;
dteny2_pre = dteny2;
dtenz1_pre =dtenz1;
dtenz2_pre = dtenz2;

ROS_INFO("X: %f,  y: %f, z: %f", mm_px, mm_py, mm_pz);
ROS_INFO("t_X: %f,  t_y: %f, t_z: %f", target_x, target_y, target_z);
ROS_INFO("dteny1: %f,  dteny2: %f, dteny3: %f, dteny4: %f, target: %f", dteny1, dteny2, dtenz1, dtenz2, tnum);
ROS_INFO("tension1: %f,tension1: %f,tension1: %f,tension1: %f", tension_v1, tension_v2, tension_v3, tension_v4 );

if (dteny1>5.00){ dteny1 = 5.00;}
if (dteny2>5.00){ dteny2 = 5.00;}
if (dtenz1>5.00){ dtenz1 = 5.00;}
if (dtenz2>5.00){ dtenz2 = 5.00;}

//dteny1 = 0.00;
//dtenz2 = 0.00;
//dtenz1 = 0.00;
//dtenz2 = 0.00;
//dtenx = 000;
//dirr = 0;
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
        r.sleep();

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





















