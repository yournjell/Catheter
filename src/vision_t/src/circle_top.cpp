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
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
 
 #include "std_msgs/String.h"
#include <std_msgs/Float32.h>
using namespace cv;
using namespace std;
 
float prev_position[4][3];
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;

int main(int argc, char** argv) {

    ros::init(argc, argv, "circle");
    ros::NodeHandle n;
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("segment_marker", 10);
    ros::Rate r(30);
  
 ros::NodeHandle position;
std_msgs::Float32 msg;




ros::Publisher position_x_pub= position.advertise<std_msgs::Float32>("position_x", 100);
ros::Publisher position_y_pub= position.advertise<std_msgs::Float32>("position_y", 100);
ros::Publisher position_z_pub= position.advertise<std_msgs::Float32>("position_z", 100);

ros::Publisher shaft_x_pub= position.advertise<std_msgs::Float32>("shaft_x", 100);
ros::Publisher shaft_y_pub= position.advertise<std_msgs::Float32>("shaft_y", 100);
ros::Publisher shaft_z_pub= position.advertise<std_msgs::Float32>("shaft_z", 100);

ros::Publisher side_f_0_pub= position.advertise<std_msgs::Float32>("side_f_0", 100);
ros::Publisher side_f_1_pub= position.advertise<std_msgs::Float32>("side_f_1", 100);
ros::Publisher side_f_2_pub= position.advertise<std_msgs::Float32>("side_f_2", 100);
ros::Publisher side_f_3_pub= position.advertise<std_msgs::Float32>("side_f_3", 100);

    float f = 0.0;

//////////////////////////////////

VideoCapture stream1(1);
VideoCapture stream0(0);

namedWindow("My Window", 1);
namedWindow("TOP", 1);

vector<Mat> spl,spl2;
 
Mat B,B2, kern;

stream1.read(B);
stream0.read(B2);			
 
kern = (Mat_<char>(3,3) << 0,-1,0,-1,10,-1,0,-1,0);

//Create trackbar to change brightness
int iSliderValue1 = 100;
createTrackbar("Brightness", "My Window", &iSliderValue1, 100);
 
//Create trackbar to change contrast
int iSliderValue2 = 100;
createTrackbar("Contrast", "My Window", &iSliderValue2, 100);
 
//Create trackbar to change contrast
int iSliderValue3 = 183;
createTrackbar("upper", "My Window", &iSliderValue3, 255);
 
 
//Create trackbar to change contrast
int iSliderValue4 = 123;
createTrackbar("lower", "My Window", &iSliderValue4, 255);
 


//Create trackbar to change brightness

int iSliderValue1a = 100;
createTrackbar("Brightness", "TOP", &iSliderValue1a, 100);
 
//Create trackbar to change contrast
int iSliderValue2a = 100;
createTrackbar("Contrast", "TOP", &iSliderValue2a, 100);
 
//Create trackbar to change contrast
int iSliderValue3a = 205;
createTrackbar("upper", "TOP", &iSliderValue3a, 255);
 
 
//Create trackbar to change contrast
int iSliderValue4a = 161;
createTrackbar("lower", "TOP", &iSliderValue4a, 255);
 

int hjh = 0;
 
	
while (ros::ok()) {
 


Mat A, A2, B, B2, H, H2, H_s, H2_s, dst, dst2;

stream1.read(B);
stream0.read(B2);
 
int iBrightness  = iSliderValue1 - 50;
int upper  = iSliderValue3;
int lower  = iSliderValue4;
double dContrast = iSliderValue2 / 50.0;

int iBrightnessa  = iSliderValue1a - 50;
int uppera  = iSliderValue3a;
int lowera  = iSliderValue4a;
double dContrasta = iSliderValue2a / 50.0;
 
B.convertTo(A, -1, dContrast, iBrightness); 
B2.convertTo(A2, -1, dContrasta, iBrightnessa); 
 
split(A,spl);
split(A2,spl2);
 
Mat C = spl[0];
Mat C2 = spl[2];

Mat C_s = spl2[0];
Mat C2_s = spl2[2];


Mat th1, th2;
Mat th1_s, th2_s;


///// REcord 1 ////////
//float target_position_x[8] = {231, 260, 322, 384, 417, 397, 329, 262};
//float target_position_z[8] = {227, 189, 167, 185, 230, 277, 295, 276};

//float target_position_y[8] = {558, 615, 617, 564, 493, 443, 445, 491};
//float target_position_xtop[8] = {94, 137, 218, 288, 297, 256, 182, 115};



//for(int h = 0; h<8; h++){


//target_position_z[h] = target_position_z[h]+30;
//target_position_y[h] = target_position_y[h]-50-160;

//}
//////////////////////////////////

float target_position_x[27] = {255, 230, 230 ,230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 230, 270, 300, 350, 430, 313, 299, 264, 229, 215, 229, 264, 299, 313 };
float target_position_z[27] = {330, 330, 330 ,330, 421, 460, 421, 330, 238, 200, 238, 330, 330, 330, 320, 310, 300, 295, 291, 347, 371, 347, 291, 234, 211, 234, 291};

float target_position_xtop[27] = {95, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 70, 110, 140, 190, 270, 153, 139, 104,  69, 54, 69, 104, 139, 153};
float target_position_y[27] = {367, 367, 417 ,467, 437, 367, 296, 267, 296, 367, 437, 467, 417, 367, 300, 250, 230, 190, 356, 359, 365, 371, 374, 371, 365, 359, 356};




int xg = 180;
int yg = 160;
int zg = 0;

for(int h = 18; h<27; h++){


target_position_x[h] = target_position_x[h]+xg;
target_position_xtop[h] = target_position_xtop[h]+xg;
target_position_y[h] = target_position_y[h]-yg;

}


for(int h = 0; h<27; h++){


target_position_z[h] = target_position_z[h]-60;

}

for (int i = 0; i<27; i++){

Point center2(target_position_x[i], target_position_z[i]);

circle(A, center2, 11, Scalar(255,0,0), 3, 8, 0); 

Point center3(target_position_y[i], target_position_xtop[i]);

circle(A2, center3, 12, Scalar(255,0,0), 3, 8, 0); 
}





/////////////////////////////
imshow("Aa", A2);//th1);
imshow("A", A);//th1);
//imshow("th2s",th2_s);
//imshow("th1s",th1_s);
  // r.sleep();


 int iKey = waitKey(50);
 
//if user press 'ESC' key
if (iKey == 27)
{
break;
}
 
 
 
}
return 0;
}

 ////////////////////// CHECK!!!! SIZE WHEN IS FAILED!!!!