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
int iSliderValue4 = 90;
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
int iSliderValue4a = 90;
createTrackbar("lower", "TOP", &iSliderValue4a, 255);
 

int hjh = 0;
 
	
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
////////////////////////////

//////////////////////////////

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

threshold(C, th1, lower,upper,CV_THRESH_BINARY);
threshold(C2, th2, lower,upper,CV_THRESH_BINARY);

threshold(C_s, th1_s, lowera,uppera,CV_THRESH_BINARY);
threshold(C2_s, th2_s, lowera,uppera,CV_THRESH_BINARY);

GaussianBlur(th1, th1, Size(9,9), 2, 2);
GaussianBlur(th2, th2, Size(9,9), 2, 2);

GaussianBlur(th1_s, th1_s, Size(9,9), 2, 2);
GaussianBlur(th2_s, th2_s, Size(9,9), 2, 2);

/// Canny detector


Canny( th1, H, lowThreshold, lowThreshold*ratio, kernel_size );
Canny( th2, H2, lowThreshold, lowThreshold*ratio, kernel_size );

/////////////////////////////
Canny( th1_s, H_s, lowThreshold, lowThreshold*ratio, kernel_size );
Canny( th2_s, H2_s, lowThreshold, lowThreshold*ratio, kernel_size );

///////////////////////////////



/////////////////////////////// SHAFT ////////////////////////////////
vector<Vec3f> circles2;   /// shaft
HoughCircles( H, circles2, CV_HOUGH_GRADIENT, 1, 20, 20, 1, 5, 7 );
 
/////////////////////////////// SHAFT ////////////////////////////////
vector<Vec3f> circles2_s;   /// shaft
HoughCircles( H_s, circles2_s, CV_HOUGH_GRADIENT, 1, 20, 20, 1, 5, 7 );
 



///////////////////SHAFT SIDE RED//////////////////////////


float distance[circles2.size()];
int shaft_point;
float distance_pre = 100000, end_shaft[2], position_side[circles2.size()][3];

for(size_t i = 0; i< circles2.size(); i++)
{
 
distance[i] = sqrt( abs(cvRound(circles2[i][0])-632)^2+abs(cvRound(circles2[i][1])-173)^2);

if (distance[i] < distance_pre){
shaft_point = i;

distance_pre = distance[i];
}

}



if (circles2.size()!=0){

//Point center2(cvRound(circles2[shaft_point][0]), cvRound(circles2[shaft_point][1]));

//int radius2 = cvRound(circles2[shaft_point][2]);

//circle(th2, center2, radius2, Scalar(255,0,255), 5, 8, 0);

end_shaft[0] = cvRound(circles2[shaft_point][0]);
end_shaft[1] = cvRound(circles2[shaft_point][1]);

}


//////////////SHAFT TOP RED/////////////////////////////////


float distance_s[circles2_s.size()];
int shaft_point_s;
float distance_pre_s = 100000, end_shaft_s[2], position_side_s[circles2_s.size()][3];

for(size_t i = 0; i< circles2_s.size(); i++)
{
 
distance_s[i] = sqrt( abs(cvRound(circles2_s[i][0])-423)^2+abs(cvRound(circles2_s[i][1])-478)^2);

if (distance_s[i] < distance_pre_s){
shaft_point_s = i;

distance_pre_s = distance_s[i];
}

}



if (circles2_s.size()!=0){

//Point center2_s(cvRound(circles2_s[shaft_point_s][0]), cvRound(circles2_s[shaft_point_s][1]));

//int radius2_s = cvRound(circles2_s[shaft_point_s][2]);

//circle(th2_s, center2_s, radius2_s, Scalar(255,0,255), 5, 8, 0);

end_shaft_s[0] = cvRound(circles2_s[shaft_point_s][0]);
end_shaft_s[1] = cvRound(circles2_s[shaft_point_s][1]);

}



///////////////////////////////////////////////////////////////////





///////////////////////////TOP SORTING RED


for(size_t i = 0; i< circles2_s.size(); i++)
{

position_side_s[i][0] = cvRound(circles2_s[i][0]);
position_side_s[i][1] = cvRound(circles2_s[i][1]);
position_side_s[i][2] = sqrt( abs(cvRound(circles2_s[i][0])-cvRound(circles2_s[shaft_point_s][0]))^2+abs(cvRound(circles2_s[i][1])-cvRound(circles2_s[shaft_point_s][1]))^2);


}


float temp_s[3];

 for (int i3s = 0; i3s < circles2_s.size(); i3s++) {
for (int i3 = 0; i3 < circles2_s.size()-1; i3++) {

if(position_side_s[i3][2] > position_side_s[i3+1][2]){

	temp_s[0] = position_side_s[i3][0];
	temp_s[1] = position_side_s[i3][1];
	temp_s[2] = position_side_s[i3][2]; 

position_side_s[i3][0] = position_side_s[i3+1][0];
position_side_s[i3][1] = position_side_s[i3+1][1];
position_side_s[i3][2] = position_side_s[i3+1][2];

position_side_s[i3+1][0] = temp_s[0];
position_side_s[i3+1][1] = temp_s[1];
position_side_s[i3+1][2] = temp_s[2];

    }//end of if
  }//end of for loop

}//end of for loop
 

///////////////////////////SIDE SORTING RED


for(size_t i = 0; i< circles2.size(); i++)
{

position_side[i][0] = cvRound(circles2[i][0]);
position_side[i][1] = cvRound(circles2[i][1]);
position_side[i][2] = sqrt( abs(cvRound(circles2[i][0])-cvRound(circles2[shaft_point][0]))^2+abs(cvRound(circles2[i][1])-cvRound(circles2[shaft_point][1]))^2);


}

float temp[3];

 for (int i3s = 0; i3s < circles2.size(); i3s++) {
for (int i3 = 0; i3 < circles2.size()-1; i3++) {

if(position_side[i3][2] > position_side[i3+1][2]){


	temp[0] = position_side[i3][0];
	temp[1] = position_side[i3][1];
	temp[2] = position_side[i3][2]; 

position_side[i3][0] = position_side[i3+1][0];
position_side[i3][1] = position_side[i3+1][1];
position_side[i3][2] = position_side[i3+1][2];

position_side[i3+1][0] = temp[0];
position_side[i3+1][1] = temp[1];
position_side[i3+1][2] = temp[2];

    }//end of if
  }//end of for loop

}//end of for loop
 

////////////////////

////SIDE BLUE//////

vector<Vec3f> circles;    
HoughCircles( H2, circles, CV_HOUGH_GRADIENT, 1, 30, 20, 1, 5, 7 );

float position_side_red[13][3], position_red_side_last[2];
position_red_side_last[0] =   position_side[1][0];
position_red_side_last[1] =   position_side[1][1];

int i2 = 0; 

for(size_t i = 0; i< circles.size(); i++)
{

position_side_red[i][0] = cvRound(circles[i][0]);
position_side_red[i][1] = cvRound(circles[i][1]);
position_side_red[i][2] = abs(position_side_red[i][0]-position_red_side_last[0]) +  abs(position_side_red[i][1]-position_red_side_last[1]);
   i2++;
 }


////TOP BLUE//////

vector<Vec3f> circles_s;    
HoughCircles( H2_s, circles_s, CV_HOUGH_GRADIENT, 1, 30, 20, 1, 5, 7 );

float position_side_red_s[13][3];
position_red_side_last[0] =   position_side_s[1][0];
position_red_side_last[1] =   position_side_s[1][1];


int i2_s = 0; 

for(size_t i = 0; i< circles_s.size(); i++)
{
	 
position_side_red_s[i][0] = cvRound(circles_s[i][0]);
position_side_red_s[i][1] = cvRound(circles_s[i][1]);
position_side_red_s[i][2] = abs(position_side_red_s[i][0]-position_red_side_last[0]) +  abs(position_side_red_s[i][1]-position_red_side_last[1]);
i2_s++;

 }

/////////////////////////////



float position_side_final[4][4];


position_side_final[0][0] = position_side_s[0][0];
position_side_final[0][1] = position_side[0][0];
position_side_final[0][2] = position_side[0][1];
position_side_final[0][3] = position_side_s[0][1];

position_side_final[1][0] = position_side_s[1][0];
position_side_final[1][1] = position_side[1][0];
position_side_final[1][2] = position_side[1][1];
position_side_final[1][3] = position_side_s[1][1];

position_side_final[2][0] = position_side_red_s[0][0];
position_side_final[2][1] = position_side_red[0][0];
position_side_final[2][2] = position_side_red[0][1];
position_side_final[2][3] = position_side_red_s[0][1];

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

float target_position_x[18] = { 313, 299, 264, 229, 215, 229, 264, 299, 313,  313, 299, 264, 229, 215, 229, 264, 299, 313 };
float target_position_z[18] = { 291, 347, 371, 347, 291, 234, 211, 234, 291,  291, 347, 371, 347, 291, 234, 211, 234, 291 };

float target_position_xtop[18] = {153, 139, 104,  69, 54, 69, 104, 139, 153,  153, 139, 104,  69, 54, 69, 104, 139, 153  };
float target_position_y[18] = {356, 359, 365, 371, 374, 371, 365, 359, 356,   356, 359, 365, 371, 374, 371, 365, 359, 356 };



int xg = 0;
int yg = 100;
int zg = 0;

for(int h = 0; h<9; h++){


target_position_x[h] = target_position_x[h]+xg-20;
target_position_xtop[h] = target_position_xtop[h]+xg-10;
target_position_y[h] = target_position_y[h]-yg;

}


for(int h = 0; h<9; h++){


target_position_z[h] = target_position_z[h]-60-50;

}





for(int h = 9; h<18; h++){


target_position_x[h] = (target_position_x[h]+xg+10)*1.3;
target_position_xtop[h] = (target_position_xtop[h]+xg+10+50)*1.3;
target_position_y[h] = (target_position_y[h]-yg-120)*1.3;
target_position_z[h] = (target_position_z[h]-60-60)*1.3;

}




for (int i = 0; i<18; i++){

Point center2(target_position_x[i], target_position_z[i]);

	if ((abs(target_position_x[i]-position_side_red[0][0])<11)&&(abs(target_position_z[i]-position_side_red[0][1])<11)){

	circle(A, center2, 11, Scalar(0,255,0), 3, 8, 0); 

	}

	else{ 
	circle(A, center2, 11, Scalar(255,0,0), 3, 8, 0); 
	}

Point center3(target_position_y[i], target_position_xtop[i]);

	if((abs(target_position_y[i]-position_side_red_s[0][0])<12)&&(abs(target_position_xtop[i]-position_side_red_s[0][1])<12)){

	circle(A2, center3, 13, Scalar(0,255,0), 3, 8, 0); 


	}

	else{ 
	circle(A2, center3, 13, Scalar(255,0,0), 3, 8, 0); 
	}

}

//////////////////////////////////////////////////////////////////////////

for(int i = 0; i < 3; i++){

Point center(position_side_final[i][1],position_side_final[i][2]);
 
circle(A, center, 11, Scalar(255,255,0), 3, 8, 0);


Point center_s(position_side_final[i][0],position_side_final[i][3]);
circle(A2, center_s, 12, Scalar(255,255,0), 3, 8, 0);

     geometry_msgs::Point p;

//if ((i2 == 1)&&( i2_s == 1)){

ROS_INFO("i2 : %d, i2_s : %d", i2, i2_s);



 	if( i2== 0 )  { p.x = (abs(position_side_final[i][3]-479)/4.0)/10; 
			p.z =0; }
	  else if(i2 == 1){ p.x = (abs(640-(position_side_final[i][1]))/3.5)/10; 

	 p.z = (-((position_side_final[i][2]-173))/3.5)/10;//((position_side_final[i][2]/4.08)-(457/4.08))*0.1;
	 

	}


	if(i2_s ==0){ p.y ==0; }
	else{ p.y =  (-((position_side_final[i][0])-410)/4.0)/10; }


  //   }





//cout <<  i2 <<" side  "<< position_side_final[2][1] <<"    top    "<< position_side_final[2][3] <<endl;

//if (hjh>100){

//if(abs(p.x-prev_position[i][0])>4){

//p.x = prev_position[i][0];

//}
//if(abs(p.y-prev_position[i][1])>4){

//p.y = prev_position[i][1];

//}
//if(abs(p.z-prev_position[i][2])>4){

//p.z = prev_position[i][2];

	
//}




//}

//else if(hjh<=100){ 
//hjh = hjh+1;


//}


	points.id = i;



prev_position[i][0] = p.x;
prev_position[i][1] = p.y;
prev_position[i][2] = p.z;

	points.color.r = 0.0f;
	points.color.g = 1.0f;
	points.color.a = 1.0;

if (i==2){

	points.color.r = 1.0f;
	points.color.g = 1.0f;
	points.color.a = 1.0;

 float end_x = end_shaft[0];
 float end_z = end_shaft[1];
 float end_y = end_shaft_s[0];

msg.data = position_side_final[3][0];
side_f_0_pub.publish(msg);
msg.data = position_side_final[3][1];
side_f_1_pub.publish(msg);
msg.data = position_side_final[3][2];
side_f_2_pub.publish(msg);
msg.data = position_side_final[3][3];
side_f_3_pub.publish(msg);

msg.data = end_x;
shaft_x_pub.publish(msg);
msg.data = end_y;
shaft_y_pub.publish(msg);
msg.data = end_z;
shaft_z_pub.publish(msg);

msg.data = p.x*10;
position_x_pub.publish(msg);
msg.data = p.y*10;
position_y_pub.publish(msg);
msg.data = p.z*10;
position_z_pub.publish(msg);


}



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

}




//cout <<" x :"<< abs((position_side_final[3][1]/1.17)-173/1.17)/10<<"y: "<<abs((position_side_final[i][0]/1.2)-478/1.2)/10<<"z :"<< abs((position_side_final[i][2]-632))/10<<endl;

    //marker_pub.publish(points);
    //marker_pub.publish(line_strip);
    //marker_pub.publish(line_list);

/////////////////////////////
imshow("Aa", A2);//th1);
imshow("A", A);//th1);
//imshow("A", H2_s);//th1);
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
