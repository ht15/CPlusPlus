#include<pthread.h>
#include<stdio.h>
//#include<unistd.h>

#define N 2

void *func(void *args);

char **ptr; // 全局变量

int main(){
    int i;
    pthread_t tid;
    int tmp[N];
    char *msgs[N] = {
        "hello from a",
        "hello from b"
    }; // 通过ptr间接引用的共享变量

    ptr = msgs;
    for (i = 0; i < N; i++){
        tmp[i] = i;
        pthread_create(&tid, NULL, func, (void*)(tmp + i));
    }
    pthread_exit(NULL);
    return 0;
}

void *func(void *args){
    int myid = *(int*)args;
    static int cnt = 0; // 静态共享变量
    printf("%d: %s cnt=%d\n", myid, ptr[myid], ++cnt);
}
