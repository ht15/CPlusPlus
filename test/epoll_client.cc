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

enum ConnState{
	Invalid = 1,
	Handshaking,
	Connected,
	Closed,
	Failed,
};
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


class TcpConn{
	int efd;
	int nfds;
	ConnState state_;
public:
	void myconnect(short port){
		int sockClient = socket(AF_INET, SOCK_STREAM, 0);
		setnonblocking(sockClient);
		struct sockaddr_in addrSrv;
		addrSrv.sin_addr.s_addr = inet_addr("127.0.0.1");
		addrSrv.sin_family = AF_INET;
		addrSrv.sin_port = htons(port);
		int r = connect(sockClient, ( const struct sockaddr *)&addrSrv, sizeof(struct sockaddr_in));
		state_ = Handshaking;
		if(r != 0 && errno != EINPROGRESS){ //when set nonblocking, connect will return -1 with errno = EINPROGRESS
			cout << "client connect error, r:"  <<r<<endl;
			close(sockClient);
			return;
		}
		cout<<"connect"<<endl;
		efd = epoll_create1(EPOLL_CLOEXEC);
		struct epoll_event ev, events[20];
		memset(&ev, 0, sizeof(ev));
		ev.events = POLLOUT|POLLIN;
		ev.data.fd = sockClient;
		r = epoll_ctl(efd, EPOLL_CTL_ADD, sockClient, &ev);
		clock_t start;
		start = clock();
		while(true){
			if((clock() - start)> 5){
				cout<<"close client, time:" << clock()<<endl;
				break;
			}
			nfds=epoll_wait(efd,events,20,500);
	        for(int i=0;i<nfds;++i)
	        {
	            if(events[i].events&POLLIN)
	            {
	            	struct pollfd pfd;
				    pfd.fd = events[i].data.fd;
				    pfd.events = POLLOUT | POLLERR;
				    int r = poll(&pfd, 1, 0); 
				    if (r == 1 && pfd.revents == POLLOUT) {  // Determine if server is available
				    	state_ = Connected;
        				cout << "Client EPOLLIN!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        			}
        			else{
        				cout << "Client:  server not available!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        				state_ = Failed;
        				struct epoll_event ev;
						memset(&ev, 0, sizeof(ev));
        				ev.data.fd = pfd.fd;
	                    epoll_ctl(efd, EPOLL_CTL_DEL, pfd.fd, &ev);
	                    close(pfd.fd);
	                    return;
        			}
	                
	            }
	            else if(events[i].events&POLLOUT) // writable
	            {
	            	if(state_ == Handshaking){
	            		state_ = Connected;
	            		cout<< "Client EPOLLOUT, Connected-----------------------------------------------" <<endl;
	            	}
	            }
	        }
	    }

	}
};

int main(){
	int pid =1;
	int port = 4028;
	TcpConn* p_con = new TcpConn();
	p_con->myconnect(port);

	printf("exit\n");
	return 0;
}