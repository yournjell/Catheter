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

void morp(Mat &thresh){

 Mat erodeElement = getStructuringElement(MORPH_RECT,Size(2,2));
 Mat dilateElement = getStructuringElement(MORPH_RECT,Size(8,8));

erode(thresh,thresh,erodeElement);
//erode(thresh,thresh,erodeElement);
dilate(thresh,thresh,dilateElement);
dilate(thresh,thresh,dilateElement);

}

void tracking_top(float &x, float &y, Mat threshold, Mat &B2){

Mat temp;
threshold.copyTo(temp);

vector< vector<Point> > contours;
vector<Vec4i> hierarchy;

findContours(temp,contours,hierarchy,CV_RETR_CCOMP,CV_CHAIN_APPROX_SIMPLE);

double refArea = 0;
bool objectFound = false;

if(hierarchy.size()>0){

	int numObjects = hierarchy.size();
	
if(numObjects<10){

	for(int index = 0; index >=0; index = hierarchy[index][0]){

		Moments moment = moments((cv::Mat)contours[index]);
		double area = moment.m00;
	
			if(area>10 ){

				//printf("%f \n",area);
				x = moment.m10/area;
				y = moment.m01/area;
				objectFound = true;		
			
				}else{ objectFound = false;
					
					}

		}
	if(objectFound = true){

		putText(B2,"Catheter Tracking",Point(0,50),2,1,Scalar(0,255,0),2);
		
Point center2(x,y);

circle(B2, center2, 11, Scalar(255,0,0), 3, 8, 0); 


		}

	}else putText(B2,"Fail", Point(0,50),1,2,Scalar(0,0,255),2);
	
		}
	

}

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

namedWindow("SIDE", 1);
namedWindow("TOP", 1);

vector<Mat> spl,spl2;
 
Mat B,B2, kern;
Mat HSV_top, HSV_Side;

stream1.read(B);
stream0.read(B2);			
 
kern = (Mat_<char>(3,3) << 0,-1,0,-1,10,-1,0,-1,0);

//Create trackbar to change brightness
int iSliderValue1 = 71;
createTrackbar("H_min", "SIDE", &iSliderValue1, 500);
 
//Create trackbar to change contrast
int iSliderValue2 = 153;
createTrackbar("H_max", "SIDE", &iSliderValue2, 500);
 
//Create trackbar to change contrast
int iSliderValue3 = 73;
createTrackbar("S_min", "SIDE", &iSliderValue3, 500);
 
 
//Create trackbar to change contrast
int iSliderValue4 = 300;
createTrackbar("S_max", "SIDE", &iSliderValue4, 500);
 
//Create trackbar to change contrast
int iSliderValue5 = 100;
createTrackbar("v_min", "SIDE", &iSliderValue5, 500);
 
//Create trackbar to change contrast
int iSliderValue6 = 251;
createTrackbar("v_max", "SIDE", &iSliderValue6, 500);
 


//Create trackbar to change brightness

int iSliderValue1a = 71; //47
createTrackbar("H_min", "TOP", &iSliderValue1a, 500);
 
//Create trackbar to change contrast
int iSliderValue2a = 153; //123
createTrackbar("H_max", "TOP", &iSliderValue2a, 500);
 
//Create trackbar to change contrast
int iSliderValue3a = 73; //73
createTrackbar("S_min", "TOP", &iSliderValue3a, 500);
 
//Create trackbar to change contrast
int iSliderValue4a = 300; //172
createTrackbar("S_max", "TOP", &iSliderValue4a, 500);
 
//Create trackbar to change contrast
int iSliderValue5a = 100; //0
createTrackbar("v_min", "TOP", &iSliderValue5a, 500);
 
//Create trackbar to change contrast
int iSliderValue6a = 251; //106
createTrackbar("v_max", "TOP", &iSliderValue6a, 500);
 

int hjh = 0;
 
Mat Top_th, Side_th;
	float x_top, y_top,x_side, y_side;
while (ros::ok()) {
 
	visualization_msgs::Marker points, line_strip, line_list;
	
	points.header.frame_id = line_strip.header.frame_id = line_list.header.frame_id =  "/catheter_shape";
	points.header.stamp = line_strip.header.stamp = line_list.header.stamp =  ros::Time::now();
	points.ns = line_strip.ns = line_list.ns = "circle";
	points.action = line_strip.action = line_list.action = visualization_msgs::Marker::ADD;
	points.pose.orientation.w = line_strip.pose.orientation.w = line_list.pose.orientation.w = 1.0;

	line_strip.id = 1;
	line_list.id = 2;

	points.type = visualization_msgs::Marker::SPHERE;
	line_strip.type = visualization_msgs::Marker::LINE_STRIP;
	line_list.type = visualization_msgs::Marker::LINE_LIST;

	points.scale.x =1;
	points.scale.y = 1;
	points.scale.z =1;

	// LINE_STRIP/LINE_LIST markers use only the x component of scale, for the line width
	line_strip.scale.x = 0.5;
	line_list.scale.x = 0.5;

	// Points are green
	points.color.r = 0.0f;
	points.color.g = 1.0f;
	points.color.a = 1.0;


	// Line strip is blue
	line_strip.color.g = 1.0;
	line_strip.color.a = 1.0;

	// Line list is red
	line_list.color.r = 1.0;
	line_list.color.a = 1.0;

stream1.read(B);  // side
stream0.read(B2);

cvtColor(B,HSV_Side,COLOR_BGR2HSV);
cvtColor(B2,HSV_top,COLOR_BGR2HSV);

inRange(HSV_Side,Scalar(iSliderValue1,iSliderValue3,iSliderValue5),Scalar(iSliderValue2,iSliderValue4,iSliderValue6),Side_th);
inRange(HSV_top,Scalar(iSliderValue1a,iSliderValue3a,iSliderValue5a),Scalar(iSliderValue2a,iSliderValue4a,iSliderValue6a),Top_th);
 
morp(Side_th);
morp(Top_th);


tracking_top(x_top,y_top, Top_th, B2);
tracking_top(x_side,y_side, Side_th, B);

     geometry_msgs::Point p;

 p.x = (abs(640-(x_side))/3.5)/10; 
 p.z = (-((y_side-93))/3.5)/10;//((position_side_final[i][2]/4.08)-(457/4.08))*0.1;
 p.y =  (-((x_top)-411)/4.0)/10;


	points.id = 1;


	points.color.r = 1.0f;
	points.color.g = 1.0f;
	points.color.a = 1.0;

msg.data = p.x*10;
position_x_pub.publish(msg);
msg.data = p.y*10;
position_y_pub.publish(msg);
msg.data = p.z*10;
position_z_pub.publish(msg);

 	points.points.push_back(p);
	line_strip.points.push_back(p);
 
        // The line list needs two points for each line
      //  line_list.points.push_back(p);
        //p.z += 1.0;
      //  line_list.points.push_back(p);
points.pose.position.x = p.x;
points.pose.position.y = p.y;
points.pose.position.z = p.z;

marker_pub.publish(points);

float side_target_x[5] = {180, 175, 169, 163, 155};
float side_target_y[5] = {112, 172, 233, 298, 358};

float top_target_x[5] = {208, 214, 224, 231, 238};
float top_target_y[5] = {81, 92, 105, 115, 122};

for(int op = 0; op <5; op++){

Point center2(top_target_x[op],top_target_y[op]);

circle(B2, center2, 11, Scalar(255,255,0), 3, 8, 0); 

Point center(side_target_x[op],side_target_y[op]);

circle(B, center, 11, Scalar(255,255,0), 3, 8, 0); 

}


/////////////////////////////
imshow("top", B2);//th1);
imshow("SIde", B);//th1);


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
