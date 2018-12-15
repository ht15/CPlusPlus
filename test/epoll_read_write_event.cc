#include <poll.h>
#include <assert.h>
#include <map>
#include <atomic>
#include <sys/time.h>
#include <sys/types.h>
#include <map>
#include <string.h>
#include <iostream>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include<unistd.h>

using namespace std;

void setnonblocking(int sock)
{
    int opts;
    opts=fcntl(sock,F_GETFL);
    if(opts<0)
    {
        perror("fcntl(sock,GETFL)");
        exit(1);
    }
    opts = opts|O_NONBLOCK;
    if(fcntl(sock,F_SETFL,opts)<0)
    {
        perror("fcntl(sock,SETFL,opts)");
        exit(1);
    }
}

class TcpServer{
	int efd;
	int nfds;
	socklen_t clilen;
public:
	void startTcpServer(string host, short port){
		struct sockaddr_in clientaddr;
		struct sockaddr_in serveraddr;
		bzero(&serveraddr, sizeof(serveraddr));
		serveraddr.sin_family = AF_INET;
		const char *local_addr="127.0.0.1";
		inet_aton(local_addr,&(serveraddr.sin_addr));//htons(portnumber);

		serveraddr.sin_port=htons(port);
		int fd = socket(AF_INET, SOCK_STREAM,0);
		setnonblocking(fd);
		// int flag = 1;
		// int len = sizeof flag;
		// setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &flag, len);
		int r = bind(fd,(sockaddr *)&serveraddr, sizeof(serveraddr));
		if(r){
			cout<< "server error" <<endl;
			close(fd);
			return;
		}
		r = listen(fd,20);
		cout<< "listening" <<endl;
		efd = epoll_create1(EPOLL_CLOEXEC);
		struct epoll_event ev, events[20];
		memset(&ev, 0, sizeof(ev));
		ev.events = POLLOUT|POLLIN;
		ev.data.fd = fd;
		r = epoll_ctl(efd, EPOLL_CTL_ADD, fd, &ev);
		int count =0;
		while(true){
			 nfds=epoll_wait(efd,events,20,500);
	        for(int i=0;i<nfds;++i)
	        {
	            if(events[i].data.fd==fd)
	            {
	                int connfd = accept(fd,(sockaddr *)&clientaddr, &clilen);
	                if(connfd<0){
	                    perror("connfd<0");
	                    exit(1);
	                }
	                cout<< " handleAccept "<<endl;
	                setnonblocking(connfd);
	                char *str = inet_ntoa(clientaddr.sin_addr);
	                cout << "accapt a connection from " << str << endl;
	                struct epoll_event ev;
					memset(&ev, 0, sizeof(ev));
	                ev.data.fd=connfd;
	                ev.events=POLLOUT|POLLIN;
	                epoll_ctl(efd,EPOLL_CTL_ADD,connfd,&ev);
	            }
	            else if(events[i].events&POLLIN)
	            {
	            	count ++;
	            	if(count >50)
	            		break;
	                cout << "server EPOLLIN#######" << endl;
	                int iConnSock = events[i].data.fd;      // 用于通信的socket
					char szBuf[1024] = {0};
	                int recvLen = recv(iConnSock, szBuf, sizeof(szBuf) - 1, 0);
	                cout << "recv: "<<recvLen<<endl;
	                if (recvLen > 0) 
					{  
	                    printf("recv data [%s] from fd [%d]\n", szBuf, iConnSock);
	                    fflush(stdout);
	                }
					else if(0 == recvLen)
					{  
	                    ev.data.fd = iConnSock;
	                    epoll_ctl(efd, EPOLL_CTL_DEL, iConnSock, &ev);
	                    close(iConnSock);
	                    printf("connection closed, local fd is [%d]\n", iConnSock);
		            }
		        }
	            else if(events[i].events&POLLOUT) // 如果有数据发送
	            {
	            	count++;
	            	if(count>50)
	            		break;
	             	cout<< "server EPOLLOUT########" <<endl;
	            }
	        }
		}
	}
};

class TcpConn{
	int efd;
	int nfds;
public:
	void myconnect(short port){
		int sockClient = socket(AF_INET, SOCK_STREAM, 0);
		setnonblocking(sockClient);
		struct sockaddr_in addrSrv;
		addrSrv.sin_addr.s_addr = inet_addr("127.0.0.1");
		addrSrv.sin_family = AF_INET;
		addrSrv.sin_port = htons(port);
		int r = connect(sockClient, ( const struct sockaddr *)&addrSrv, sizeof(struct sockaddr_in));
		if(r != 0 && errno != EINPROGRESS){ //when set nonblocking, connect will return -1 with errno = EINPROGRESS
			cout << "client connect error, r:"  <<r<<endl;
			close(sockClient);
			return;
		}
		cout<<"connect"<<endl;
		// efd = epoll_create1(EPOLL_CLOEXEC);
		// struct epoll_event ev, events[20];
		// memset(&ev, 0, sizeof(ev));
		// ev.events = POLLOUT|POLLIN;
		// ev.data.fd = sockClient;
		// r = epoll_ctl(efd, EPOLL_CTL_ADD, sockClient, &ev);
		// clock_t start;
		// start = clock();
		// while(true){
		// 	if((clock() - start)> 5){
		// 		cout<<"close client, time:" << clock()<<endl;
		// 		break;
		// 	}
		// 	nfds=epoll_wait(efd,events,20,500);
	 //        for(int i=0;i<nfds;++i)
	 //        {
	 //            if(events[i].events&POLLIN)
	 //            {
	 //                cout << "Client EPOLLIN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	 //            }
	 //            else if(events[i].events&POLLOUT) // writable
	 //            {
	 //             	cout<< "Client EPOLLOUT-----------------------------------------------" <<endl;
	 //            }
	 //        }
	 //    }

	}
};

int main(){
	int pid =1;
	int port = 4028;
	cout<< "server process"<<endl;
	TcpServer* p_svr = new TcpServer();
	p_svr->startTcpServer("", port);
	printf("exit\n");
	return 0;
}