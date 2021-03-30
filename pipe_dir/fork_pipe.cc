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
    pid_t pid;

    if(pipe(fds) == -1)
        perror("make pipe"),exit(1);

    //读取数据
    pid = fork();
    if(pid == -1){
        exit(1);
    }else if(pid == 0)
    {
        printf("pid: %d, ppid:%d\n", getpid(), getppid());
        close(fds[0]); //建议关闭子进程的读
        len = strlen(buf);
        //写入管道
        if(write(fds[1], "", 1) != 1)
        {
            perror("write to pipe");
        }
        printf("process %d: send msg ''\n", getpid());
        sleep(2);

        printf("process %d: close fds[1] \n", getpid());
        close(fds[1]);
    }else{
        printf("pid: %d\n", getpid());
        //父进程从管道中读取
        //首先关闭写
        close(fds[1]); //建议关闭父进程的写
        while(1){
            len=read(fds[0],buf,100);
            if(len == -1)
            {
                perror("read from pipe");
                exit(1);
            }
            else if(len == 0){
                printf("process %d: will close fds[0]\n", getpid());
                close(fds[0]);
                break;
            }
            else{
                printf("process %d: recv len:%d\n", getpid(), len);
                printf("process %d: read from pipe: %s\n", getpid(), buf);
            }
        }
    }
}
