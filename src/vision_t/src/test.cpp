
VideoCapture stream1(1);
VideoCapture stream2(0);


namedWindow("My Window", 1);

vector<Mat> spl,spl2;
 
Mat B,B2, kern;

//stream1 >> B;
stream1.read(B);
stream2.read(B2);		
 
kern = (Mat_<char>(3,3) << 0,-1,0,-1,10,-1,0,-1,0);
Mat new_image = Mat::zeros( B.size(), B.type() );
 
//Create trackbar to change brightness
int iSliderValue1 = 50;
createTrackbar("Brightness", "My Window", &iSliderValue1, 100);
 
//Create trackbar to change contrast
int iSliderValue2 = 50;
createTrackbar("Contrast", "My Window", &iSliderValue2, 100);
 
//Create trackbar to change contrast
int iSliderValue3 = 1;
createTrackbar("upper", "My Window", &iSliderValue3, 255);
 
 
//Create trackbar to change contrast
int iSliderValue4 = 1;
createTrackbar("lower", "My Window", &iSliderValue4, 255);


int main(int argc, char** argv) {

	


 
 
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

//////////////////////////////////////////




Mat A,A2, B,B2, H, H2;
stream1.read(B);
stream2.read(B2);
 
Mat dst;
int iBrightness  = iSliderValue1 - 50;
int upper  = iSliderValue3;
int lower  = iSliderValue4;
double dContrast = iSliderValue2 / 50.0;
 
B.convertTo(A, -1, dContrast, iBrightness); 
B2.convertTo(A2, -1, dContrast, iBrightness); 
 
split(A,spl);
 
Mat C = spl[0];
Mat C2 = spl[2];

Mat th1, th2;

threshold(C, th1, lower,upper,CV_THRESH_BINARY);
threshold(C2, th2, lower,upper,CV_THRESH_BINARY);

GaussianBlur(th1, th1, Size(9,9), 2, 2);
GaussianBlur(th2, th2, Size(9,9), 2, 2);
/// Canny detector
Canny( th1, H, lowThreshold, lowThreshold*ratio, kernel_size );
Canny( th2, H2, lowThreshold, lowThreshold*ratio, kernel_size );

///////////////////////////////


/////////////////////////////// SHAFT ////////////////////////////////
vector<Vec3f> circles2;   /// shaft
HoughCircles( H2, circles2, CV_HOUGH_GRADIENT, 1, 20, 20, 1, .1, 10 );
 


float distance[circles2.size()];
int shaft_point;
float distance_pre = 0, end_shaft[2];

for(size_t i = 0; i< circles2.size(); i++)
{
 

distance[i] = sqrt( abs(cvRound(circles2[i][0])-397)^2+abs(cvRound(circles2[i][1])-476)^2);

cout<<" distance: " << distance[i]	<<endl;

if (distance[i] >= distance_pre){
shaft_point = i;

distance_pre = distance[i];
}


}


if (circles2.size()!=0){

Point center2(cvRound(circles2[shaft_point][0]), cvRound(circles2[shaft_point][1]));
int radius2 = cvRound(circles2[shaft_point][2]);
//cout<< "center :" << center2 << "\nradius:" << circles2.size() << endl;
circle(th2, center2, radius2, Scalar(255,0,255), 5, 8, 0);

end_shaft[0] = cvRound(circles2[shaft_point][0]);
end_shaft[1] = cvRound(circles2[shaft_point][1]);

cout<<" shaft_point: " << distance[shaft_point]	<<" shaft_point: " <<  end_shaft[0]  <<" shaft_point: " << end_shaft[1] <<endl;


}




////////////////////////////////////////////////////////////////////////////////////




/////////////////////////////////tip
vector<Vec3f> circles;    
HoughCircles( H, circles, CV_HOUGH_GRADIENT, 1, 20, 20, 1, .1, 5 );
 
//HoughCircles( H, circles, CV_HOUGH_GRADIENT, 1, H.rows/2, 20, 1, .1, 10 );
float segment_l[13][3]; 

int i2 = 0; 

for(size_t i = 0; i< circles.size(); i++)
{
	if ((cvRound(circles[i][1])<end_shaft[1])){
 
segment_l[i2][0] = cvRound(circles[i][0]);
segment_l[i2][1] = cvRound(circles[i][1]);
segment_l[i2][2] = sqrt( abs(cvRound(circles2[shaft_point][0])-cvRound(circles[i][0]))^2 + abs(cvRound(circles2[shaft_point][1])-cvRound(circles[i][1]))^2 );

i2++;

 }
 
}
 
///////////////////////////////Sorting//////

float temp[3];

for(int i =0; i<=i2+1; i++){

	for(int i3 =0; i3<i2+1; i3++){


	if(segment_l[i3][2] > segment_l[i3+1][2]){

	temp[0] = segment_l[i3][0];
	temp[1] = segment_l[i3][1];
	temp[2] = segment_l[i3][2]; 
		
segment_l[i3][0] = segment_l[i3+1][0];
segment_l[i3][1] = segment_l[i3+1][1];
segment_l[i3][2] = segment_l[i3+1][2];

segment_l[i3+1][0] = temp[0];
segment_l[i3+1][1] = temp[1];
segment_l[i3+1][2] = temp[2];

		}
		 }
		  }


for(int i = 0; i < i2; i++){
cout<<"segment : "<<segment_l[i][2]<<endl;
 

Point center(segment_l[i][0], segment_l[i][1]);
int radius = cvRound(circles[i][2]);
 
circle(A, center, 10, Scalar(255,255,0), 1, 8, 0);

}

cout<<"segment number : "<<i2<<endl;
///////////////////////////////////////////////////////////////////////////////////

for(int i = 0; i < i2; i++){

     geometry_msgs::Point p;

       p.x = segment_l[i][0];
       p.y = segment_l[i][1];
       p.z = 0;


        points.points.push_back(p);
        line_strip.points.push_back(p);
 
        // The line list needs two points for each line
        line_list.points.push_back(p);
        p.z += 1.0;
        line_list.points.push_back(p);


}

    marker_pub.publish(points);
    marker_pub.publish(line_strip);
    marker_pub.publish(line_list);
 

/////////////////////////////
imshow("A", A);//th1);
imshow("th2", A2);//th1);
imshow("th1", th1);

   r.sleep();
 int iKey = waitKey(50);
 
//if user press 'ESC' key
if (iKey == 27)
{
break;
}
 
 
 
}
return 0;
}
 
