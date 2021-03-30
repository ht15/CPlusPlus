#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define ERR_EXIT(m) \
    do \
{ \
    perror(m); \
    exit(EXIT_FAILURE); \
}while(0)

int main()
{
       int outfd;
       char buf[1024];

       mkfifo("tp.c", 0644);//创建命名管道文件
       outfd = open("tp.c", O_WRONLY);
       if(outfd == -1)
           ERR_EXIT("open");

       char *qiqi = "qiqi shi bendan, ni shuo shibushi 我觉得没问题";
       write(outfd, qiqi, strlen(qiqi));//变量内容写到管道文件中

       close(outfd);//关闭写操作

       return 0;
}
