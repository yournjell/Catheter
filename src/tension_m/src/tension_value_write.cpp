#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
 #include <sys/stat.h>
#include <termios.h>
#include <fcntl.h>
#include <iostream>
#include <sstream>
#include <math.h>
 #include "ros/ros.h"
 #include "std_msgs/String.h"
#include <std_msgs/Float32.h>

#include <time.h>

using namespace std;

double tension1 ;
double tension2 ;
double tension3 ;
double tension4 ;
unsigned char buf2[25];
double speed[25] = {1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};


float dis_x,dis_xa,tension_w,tension_w2,tension_w3, tension_w4, tension_v1,  tension_v2,  tension_v3,tension_v4;
float printt(float g);
/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
// %Tag(CALLBACK)%

void tension1a(const std_msgs::Float32 & msg)
{
tension_w = msg.data;
 //ROS_INFO("1: [%f]", tension_w);

tension_v1 = printt(tension_w);


}


void tension2a(const std_msgs::Float32 & msg)
{
tension_w2 = msg.data;
 //ROS_INFO("1: [%f]", tension_w);

tension_v2 = printt(tension_w2);


}


void tension3a(const std_msgs::Float32 & msg)
{
tension_w3 = msg.data;
 //ROS_INFO("1: [%f]", tension_w);

tension_v3 = printt(tension_w3);


}


void tension4a(const std_msgs::Float32 & msg)
{
tension_w4 = msg.data;
 //ROS_INFO("1: [%f]", tension_w);

tension_v4 = printt(tension_w4);


}


void position_xx(const std_msgs::Float32 & msg)
{
dis_x = msg.data;
 //ROS_INFO("1: [%f]", tension_w);

dis_xa = printt(dis_x);


}


float printt(float b){
//ROS_INFO("here");
//cout<< b<<endl;

return b;
}


/////////////////////


int serialport_init(const char* serialport, int baud)
{
    struct termios newtio;
    int fd;
    
    //fd = open(serialport, O_RDWR | O_NOCTTY | O_NDELAY);
    fd = open(serialport, O_RDWR | O_NONBLOCK | O_NOCTTY  );
    
   // /dev/ttyS0를 사용하기 위해 open()함수를 사용합니다.
   // O_RDWR은 파일 디스크립터인 fd를 읽기와 쓰기 모드로 열기 위한 지정이며
   // O_NOCCTY와 O_NONBLOCK는 시리얼 통신 장치에 맞추어 추가했습니다.

 //  memset( &newtio, 0, sizeof(newtio) );

   // 시리얼 통신환경 설정을 위한 구조체 변수 newtio 값을 0 바이트로 깨끗이 채웁니다. 

  // END Serial Available
   newtio.c_cflag = B115200;   // 통신 속도 115200 
   newtio.c_cflag |= CS8;      // 데이터 비트가 8bit 
   newtio.c_cflag |= CLOCAL;   // 외부 모뎀을 사용하지 않고 내부 통신 포트 사용 
   newtio.c_cflag |= CREAD;    // 쓰기는 기본, 읽기도 가능하게 
   newtio.c_iflag = 1;         // parity 비트는 없음
   newtio.c_oflag = 0;
   newtio.c_lflag = 0;
   newtio.c_cc[VTIME] = 1; 
   newtio.c_cc[VMIN] = 0; 

   tcflush (fd, TCIFLUSH );
   tcsetattr(fd, TCSANOW, &newtio );   // 포트에 대한 통신 환경을 설정합니다. 

    return fd;
}




int main( int argc, char **argv)
{  

ros::init(argc, argv, "tension");
ros::NodeHandle nn1,de_t;
std_msgs::Float32 msg;

ros::Publisher tension11_pub= nn1.advertise<std_msgs::Float32>("tension11", 100);
ros::Publisher tension21_pub= nn1.advertise<std_msgs::Float32>("tension21", 100);
ros::Publisher tension31_pub= nn1.advertise<std_msgs::Float32>("tension31", 100);
ros::Publisher tension41_pub= nn1.advertise<std_msgs::Float32>("tension41", 100);

ros::Subscriber sub1 = de_t.subscribe("desired_tz1", 100, tension1a);
ros::Subscriber sub2 = de_t.subscribe("desired_tz2", 100, tension2a);
ros::Subscriber sub3 = de_t.subscribe("desired_ty1", 100, tension3a);
ros::Subscriber sub4 = de_t.subscribe("desired_ty2", 100, tension4a);
ros::Subscriber sub5 = de_t.subscribe("desired_dis", 100, position_xx);



int hj = serialport_init("/dev/ttyACM0", 115200);
usleep(3500000);


  ros::Rate loop_rate(100);
while(ros::ok()){


  char* str1 = new char[30];
  char* str2 = new char[30];
  char* str3 = new char[30];
  char* str4 = new char[30];
  char* str5 = new char[30];
 
    sprintf(str1, "%.4g", tension_v1);  
    sprintf(str2, "%.4g", tension_v2 );  
    sprintf(str3, "%.4g", tension_v3 );  
    sprintf(str4, "%.4g", tension_v4 );  
    sprintf(str5, "%.4g", dis_xa );   
 

   // cout<<"  1: "<<str1<<"  2: "<<str2<<"  3: "<<str3<<"  4: "<<str4<<endl;

//buf[0] = (char)tension_v1 ;
//buf[1] = (char)tension_v4;
//buf[2] = (char)tension_v3;
//buf[3] = (char)tension_v2;
//buf[4] = (char)dis_xa;

//////////////////////////////////////////

char buf[5]={0,0,0,0,1};

      write(hj,buf,5);



	int tension[25], k = 24;

	unsigned char n = read(hj, buf2,25);
		

	for(int ii = 0; ii<25; ii++){

	int ll = (int)(buf2[ii]);
	tension[24-ii] = ll-48;
//printf("%d ",ll-48);
	}

 //  tcflush (fd, TCIFLUSH );

//printf("\n  ");




		int i1 = 0, deci = 2, state_bit;
		double tension_fr[10] = {0};

			for(int j = 0; j<25; j++){

			//printf("%d ",tension[j]);
				if(tension[j]==-2){ 
					i1 = i1+1; 
					deci = 2; }
				else {

		tension_fr[i1]= (tension[j]/pow10(deci)) + tension_fr[i1];
			deci = deci-1;

			}


			//printf("%d ", tension[j]);

			}


			for(int j = 0; j<10; j++){

			if(tension_fr[9-j] == 7.77){

			 tension1 = tension_fr[9-j-1];
			 tension2 = tension_fr[9-j-2];
			 tension3 = tension_fr[9-j-3];
			 tension4 = tension_fr[9-j-4];

			printf("tension 1: %f tension 2: %f tension 3: %f tension 4: %f ", tension1, tension2, tension3, tension4);
			break;
			}

			else if(j == 19){

			printf("tension 1: %f tension 2: %f tension 3: %f tension 4: %f ", tension1, tension2, tension3, tension4);


			} 

			}




msg.data = tension1;
tension11_pub.publish(msg);
msg.data = tension2;
tension21_pub.publish(msg);
msg.data = tension3;
tension31_pub.publish(msg);
msg.data = tension4;
tension41_pub.publish(msg);

usleep(2);
printf("\n");


        ros::spinOnce();
        loop_rate.sleep();


}

close(hj);

 return 0; 
}
