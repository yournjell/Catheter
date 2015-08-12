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
   newtio.c_cflag = B115200 ;   // 통신 속도 115200 
   newtio.c_cflag |= CS8;      // 데이터 비트가 8bit 
   newtio.c_cflag |= CLOCAL;   // 외부 모뎀을 사용하지 않고 내부 통신 포트 사용 
  // newtio.c_cflag |= CREAD;    // 쓰기는 기본, 읽기도 가능하게 
   newtio.c_iflag = 0;         // parity 비트는 없음
   newtio.c_oflag = 0;
   newtio.c_lflag = 0;
   newtio.c_cc[VTIME] = 1; 
   newtio.c_cc[VMIN] = 0; 
   cfsetospeed(&newtio,B115200 ); // 115200 baud
   cfsetispeed(&newtio,B115200 ); // 115200 baud
   tcflush (fd, TCIFLUSH );
   tcsetattr(fd, TCSANOW, &newtio );   // 포트에 대한 통신 환경을 설정합니다. 

    return fd;
}




int main( int argc, char **argv)
{  


int hj = serialport_init("/dev/ttyS0", 14400);
usleep(350000);


printf("REady\n");
while(1){



//printf("%d , %d, %d,%d , %d, %d,%d , %d, %d,%d , %d, %d,%d , %d, %d", buf1[0], buf1[1], buf1[2], buf1[3], buf1[4], buf1[5], buf1[6], buf1[7], buf1[8], buf1[9], buf1[10], buf1[11], buf1[12], buf1[13], buf1[14]);       



	char buf2[100];

	char n = read(hj, buf2,100);
	
	printf("%c",n);
		
printf("\n");
usleep(2);


}

close(hj);

 return 0; 
}
