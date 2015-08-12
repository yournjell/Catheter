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
 
using namespace cv;
using namespace std;
 

int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3;

int main(int argc, char** argv) {

    ros::init(argc, argv, "circle");
    ros::NodeHandle n;
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("segment_marker", 10);
    ros::Rate r(30);
  
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
int iSliderValue4 = 65;
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
int iSliderValue4a = 180;
createTrackbar("lower", "TOP", &iSliderValue4a, 255);
 
 
while (ros::ok()) {
 


	visualization_msgs::Marker points, line_strip, line_list;
	points.header.frame_id = line_strip.header.frame_id = line_list.header.frame_id = "/catheter_shape";
	points.header.stamp = line_strip.header.stamp = line_list.header.stamp = ros::Time::now();
	points.ns = line_strip.ns = line_list.ns = "circle";
	points.action = line_strip.action = line_list.action = visualization_msgs::Marker::ADD;
	points.pose.orientation.w = line_strip.pose.orientation.w = line_list.pose.orientation.w = 1.0;

	points.id = 0;
	line_strip.id = 1;
	line_list.id = 2;

	points.type = visualization_msgs::Marker::POINTS;
	line_strip.type = visualization_msgs::Marker::LINE_STRIP;
	line_list.type = visualization_msgs::Marker::LINE_LIST;


	points.scale.x = 0.2;
	points.scale.y = 0.2;
	// LINE_STRIP/LINE_LIST markers use only the x component of scale, for the line width
	line_strip.scale.x = 0.1;
	line_list.scale.x = 0.1;



	// Points are green
	points.color.g = 1.0f;
	points.color.a = 1.0;

	// Line strip is blue
	line_strip.color.b = 1.0;
	line_strip.color.a = 1.0;

	// Line list is red
	line_list.color.r = 1.0;
	line_list.color.a = 1.0;


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
 
distance[i] = sqrt( abs(cvRound(circles2[i][0])-632)^2+abs(cvRound(circles2[i][1])-236)^2);

if (distance[i] < distance_pre){
shaft_point = i;

distance_pre = distance[i];
}

}



if (circles2.size()!=0){

Point center2(cvRound(circles2[shaft_point][0]), cvRound(circles2[shaft_point][1]));

int radius2 = cvRound(circles2[shaft_point][2]);

circle(th2, center2, radius2, Scalar(255,0,255), 5, 8, 0);

end_shaft[0] = cvRound(circles2[shaft_point][0]);
end_shaft[1] = cvRound(circles2[shaft_point][1]);

}

//////////////////////////////////SHAFT TOP RED/////////////////////////////////


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

Point center2_s(cvRound(circles2_s[shaft_point_s][0]), cvRound(circles2_s[shaft_point_s][1]));

int radius2_s = cvRound(circles2_s[shaft_point_s][2]);

circle(th2_s, center2_s, radius2_s, Scalar(255,0,255), 5, 8, 0);

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
cout<<""<<endl;

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
 


////SIDE BLUE//////

vector<Vec3f> circles;    
HoughCircles( H2, circles, CV_HOUGH_GRADIENT, 1, 30, 20, 1, 5, 7 );

float position_side_red[13][3]; 

int i2 = 0; 

for(size_t i = 0; i< circles.size(); i++)
{
	if ((cvRound(circles[i][0])<position_side[0][0]-10)){
 
position_side_red[i2][0] = cvRound(circles[i][0]);
position_side_red[i2][1] = cvRound(circles[i][1]);
position_side_red[i2][2] = sqrt( abs(cvRound(circles2[shaft_point][0])-cvRound(circles[i][0]))^2 + abs(cvRound(circles2[shaft_point][1])-cvRound(circles[i][1]))^2 );

i2++;
}
 }
////TOP BLUE//////

vector<Vec3f> circles_s;    
HoughCircles( H2_s, circles_s, CV_HOUGH_GRADIENT, 1, 25, 20, 1, 12, 15 );

float position_side_red_s[13][3]; 

int i2_s = 0; 

for(size_t i = 0; i< circles_s.size(); i++)
{
	if ((cvRound(circles_s[i][1])<position_side_s[0][1])){
 
position_side_red_s[i2_s][0] = cvRound(circles_s[i][0]);
position_side_red_s[i2_s][1] = cvRound(circles_s[i][1]);
position_side_red_s[i2_s][2] = sqrt( abs(cvRound(circles2_s[shaft_point_s][0])-cvRound(circles_s[i2_s][0]))^2 + abs(cvRound(circles2_s[shaft_point_s][1])-cvRound(circles_s[i2_s][1]))^2 );

i2_s++;
}
 }

//////////////////////SORTING RED SIDE//////////////////////



 for (int i3s = 0; i3s < circles2.size(); i3s++) {
for (int i3 = 0; i3 < circles2.size()-1; i3++) {

if(position_side_red[i3][2] > position_side_red[i3+1][2]){

	temp[0] = position_side_red[i3][0];
	temp[1] = position_side_red[i3][1];
	temp[2] = position_side_red[i3][2]; 

position_side_red[i3][0] = position_side_red[i3+1][0];
position_side_red[i3][1] = position_side_red[i3+1][1];
position_side_red[i3][2] = position_side_red[i3+1][2];

position_side_red[i3+1][0] = temp[0];
position_side_red[i3+1][1] = temp[1];
position_side_red[i3+1][2] = temp[2];

    }//end of if
  }//end of for loop

}//end of for loop



//////////////////////SORTING RED top//////////////////////



 for (int i3s = 0; i3s < circles2_s.size(); i3s++) {
for (int i3 = 0; i3 < circles2_s.size()-1; i3++) {

if(position_side_red_s[i3][2] > position_side_red_s[i3+1][2]){

	temp_s[0] = position_side_red_s[i3][0];
	temp_s[1] = position_side_red_s[i3][1];
	temp_s[2] = position_side_red_s[i3][2]; 

position_side_red_s[i3][0] = position_side_red_s[i3+1][0];
position_side_red_s[i3][1] = position_side_red_s[i3+1][1];
position_side_red_s[i3][2] = position_side_red_s[i3+1][2];

position_side_red_s[i3+1][0] = temp_s[0];
position_side_red_s[i3+1][1] = temp_s[1];
position_side_red_s[i3+1][2] = temp_s[2];

    }//end of if
  }//end of for loop

}//end of for loop






float position_side_final[4][4];

position_side_final[0][0] = position_side_s[0][0];
position_side_final[0][1] = position_side[0][0];
position_side_final[0][2] = position_side[0][1];
position_side_final[0][3] = position_side_s[0][1];

position_side_final[1][0] = position_side_red_s[0][0];
position_side_final[1][1] = position_side_red[0][0];
position_side_final[1][2] = position_side_red[0][1];
position_side_final[1][3] = position_side_red_s[0][1];


position_side_final[2][0] = position_side_s[1][0];
position_side_final[2][1] = position_side[1][0];
position_side_final[2][2] = position_side[1][1];
position_side_final[2][3] = position_side_s[1][1];


position_side_final[3][0] = position_side_red_s[1][0];
position_side_final[3][1] = position_side_red[1][0];
position_side_final[3][2] = position_side_red[1][1];
position_side_final[3][3] = position_side_red_s[1][1];

int i = 0;	
for(int i = 0; i < 4; i++){

Point center(position_side_final[i][1],position_side_final[i][2]);
 
circle(A, center, 10, Scalar(255,255,0), 3, 8, 0);


Point center_s(position_side_final[i][0],position_side_final[i][3]);
 
circle(A2, center_s, 10, Scalar(255,255,0), 3, 8, 0);

cout <<"  0 "<< position_side_final[i][0]<<" 3  "<< position_side_final[i][3]<<" 1  "<< position_side_final[i][1]<<" 2  "<< position_side_final[i][2]<<"   "<< circles2.size()<<"   "<< circles.size()<<endl;

     geometry_msgs::Point p;

       p.x = ((position_side_final[i][1]/4)-(226/4))*0.1;
       p.y  = ((position_side_final[i][2]/3.333)-(407/3.333))*0.1;
       p.z = i;//((position_side_final[i][2]/4.08)-(457/4.08))*0.1;


        points.points.push_back(p);
        line_strip.points.push_back(p);
 
        // The line list needs two points for each line
        line_list.points.push_back(p);
        //p.z += 1.0;
        line_list.points.push_back(p);


}

    marker_pub.publish(points);
    marker_pub.publish(line_strip);
    marker_pub.publish(line_list);

/////////////////////////////
imshow("Aa", A2);//th1);
imshow("A", A);//th1);
imshow("th2s",th2_s);
imshow("th1s",th1_s);
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
