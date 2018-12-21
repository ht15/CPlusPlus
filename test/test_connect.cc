#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <malloc.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <stdarg.h>
#include <fcntl.h>
#include <fcntl.h>
using namespace std;

int main()
{
	 int err;
	 if ( err != 0 ) {
	  	return 1;
	 }
	 int sockClient=socket(AF_INET,SOCK_STREAM,0);
	 
	 sockaddr_in addrSrv;
	 addrSrv.sin_addr.s_addr = inet_addr("127.0.0.1");
	 addrSrv.sin_family=AF_INET;
	 addrSrv.sin_port=htons(4000);
	 connect(sockClient,( const struct sockaddr *)&addrSrv, sizeof(struct sockaddr_in));
	 // send(sockClient,"hello",strlen("hello")+1,0);
	 // char recvBuf[50];
	 // recv(sockClient,recvBuf,50,0);
	 // printf("%s\n",recvBuf);
	 
	 close(sockClient);
	 return 0;
}