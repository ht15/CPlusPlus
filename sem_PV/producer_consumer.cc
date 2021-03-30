#include "macos_sem.h"
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

const int PRODUCER_NUM = 3;
const int CONSUMER_NUM = 5;

const int BUFF_NUM = 10;


void P(struct rk_sem *s){
    rk_sem_wait(s);
}

void V(struct rk_sem *s){
    rk_sem_post(s);
}
struct SBuff {
    int n; // buff 的长度
    int *buf; // buff的实际存储
    int insert_index; // 数据插入的index
    int pop_index; // 数据取出的index
    struct rk_sem mutex; // 对某一index的操作应该是互斥操作，因为可能对同一index同时进行insert和pop
    struct rk_sem slots; // 只有slots不能空才能插入数据
    struct rk_sem items; // 只有items不为空才能取出数据
};
static SBuff sbuff;

void init_sbuff(SBuff *buff, int n){
    // 值传递会产生值拷贝，不会对原对象产生影响。
    if(n < 1)
        return;
    buff->n = n;
    buff->buf = (int*)malloc(sizeof(int) * n);
    buff->insert_index = 0;
    buff->pop_index = 0;
    rk_sem_init(&buff->mutex, 1);
    rk_sem_init(&buff->slots, n);
    rk_sem_init(&buff->items, 0);
}

void release_sbuff(SBuff *buff){
    free(buff->buf);
}

void insert_sbuff(SBuff *buff, int item){
    P(&buff->slots);
    P(&buff->mutex);
    buff->buf[++buff->insert_index % buff->n] = item;
    V(&buff->mutex);
    V(&buff->items);
}

int pop_sbuff(SBuff *buff){
    int item;
    P(&buff->items);
    P(&buff->mutex);
    item = buff->buf[++buff->pop_index % buff->n];
    V(&buff->mutex);
    V(&buff->slots);
    return item;
}

void* producer_func(void *p){
    pthread_detach(pthread_self());
    for(int i=0;i<50;i++){
        insert_sbuff(&sbuff, i);
        sleep(1);
    }
}

void* consumer_func(void *p){
    pthread_detach(pthread_self());
    for(int i=0;i<30;i++){
        printf("consumer is :%d\n", pop_sbuff(&sbuff));
        sleep(2);
    }
}

int main(int argc, const char* argv[]){
    init_sbuff(&sbuff, BUFF_NUM);

    pthread_t producer[PRODUCER_NUM];
    pthread_t consumer[CONSUMER_NUM];
    
    for(int i = 0; i < PRODUCER_NUM; i++){
        pthread_create(&producer[i], NULL, producer_func, NULL);
    }

    for(int i = 0; i < CONSUMER_NUM; i++){
        pthread_create(consumer + i, NULL, consumer_func, NULL);
    }

    pthread_exit(NULL);
    release_sbuff(&sbuff);
}
