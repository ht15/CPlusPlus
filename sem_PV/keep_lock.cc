#include<pthread.h>
// #include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>
#include "macos_sem.h"

void P(struct rk_sem *s);
void V(struct rk_sem *s);

void *func(void *p);

static rk_sem sem1;

static void init_sem(){
    rk_sem_init(&sem1, 1);
}

// 主线程中的全局变量，或者是子线程中的静态变量 都是所有线程共享的。
int thread_num = 10;

int total_count = 0;

int main(int argc, const char* argv[]){

    if(argc != 2){
        printf("use %s add_count\n", argv[0]);
        exit(0);
    }
    int add_count = atoi(argv[1]);
    pthread_t tid[thread_num];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    for(int i=0;i<thread_num;i++){
        pthread_create(&tid[i],&attr,func, &add_count);
    }

    for(int i=0; i<thread_num; i++){
        pthread_join(tid[i], NULL);
    }
    printf("total count is %d\n", total_count);
    return 0;
}

void P(struct rk_sem *s){
    rk_sem_wait(s);
}

void V(struct rk_sem *s){
    rk_sem_post(s);
}

void *func(void *add_count){
    static pthread_once_t once = PTHREAD_ONCE_INIT;
    pthread_once(&once, init_sem);
    //P(&sem1);
    *((int*)add_count) = 4;
    total_count += *((int*)add_count);
    //V(&sem1);
    // pthread_exit(NULL);
}
