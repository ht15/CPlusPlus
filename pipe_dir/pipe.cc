#include <sys/types.h>  
#include <sys/ipc.h>  
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int fds[2];
    char buf[100];
    int len;

    if(pipe(fds) == -1)
        perror("make pipe"),exit(1);

    //读取数据
    while(fgets(buf,100,stdin))
    {
        len = strlen(buf);
        //写入管道
        if(write(fds[1],buf,len) != len)
        {
            perror("write to pipe");
            break;
        }
        // memset(buf,0x00,sizeof(buf));

        //从管道中读取
        if((len=read(fds[0],buf,100)) == -1)
        {
            perror("read from pipe");
            break;
        }

        //显示管道中内容
        if(write(1,buf,len) != len)
        {
            perror("write to stdout");
            break;
        }
    }
}
