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
#include <tension_m/tension.h>

#include <time.h>

using namespace std;

double tension1 ;
double tension2 ;
double tension3 ;
double tension4 ;
unsigned char buf2[25];
double speed[25] = {1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};



float dis_x,dis_xa,distance_dir,distance_dirp;
float printt(float g);
/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
// %Tag(CALLBACK)%

void distance_d(const std_msgs::Float32 & msg)
{
distance_dirp = msg.data;
 //ROS_INFO("1: [%f]", tension_w);

distance_dir = printt(distance_dirp);


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
   cfsetospeed(&newtio,B115200); // 115200 baud
   cfsetispeed(&newtio,B115200); // 115200 baud
   tcflush (fd, TCIFLUSH );
   tcsetattr(fd, TCSANOW, &newtio );   // 포트에 대한 통신 환경을 설정합니다. 

    return fd;
}






int main( int argc, char **argv)
{  


ros::init(argc, argv, "translation");
ros::NodeHandle nn1,de_t,mm;

//std_msgs::tension msg;


//


ros::Subscriber sub5 = de_t.subscribe("desired_dis", 100, position_xx);
ros::Subscriber sub6 = de_t.subscribe("desired_dir", 100, distance_d);



int hj2 = serialport_init("/dev/ttyACM1", 115200);
usleep(3500000);


  ros::Rate loop_rate(100);

printf("REady\n");
while(ros::ok()){

int pp = 0;
int ll = 0;
int pd = dis_xa/100;
pp = (dis_xa-(pd*100))/10;
int p2d = pp;
ll = (dis_xa-(pd*100)-(p2d*10));
int p3d = ll;
pp = (dis_xa-(pd*100)-(p2d*10)-p3d)*10;
int p4d = pp;

int pdir = distance_dir;

//char* p_arr[1] = reinterpret_cast<char*>(arr[0]);

char buf1[7]={8,pd,p2d,p3d,p4d,pdir,6};
    
ROS_INFO("%i, %i, %i, %i, %i, %i, %i,", buf1[0], buf1[1], buf1[2], buf1[3], buf1[4], buf1[5], buf1[6]);

  write(hj2,buf1,7);
 
usleep(2);


        ros::spinOnce();
        loop_rate.sleep();


}

close(hj2);

 return 0; 
}