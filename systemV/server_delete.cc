/*server.c:向共享内存中写入People*/  
#include <stdio.h>  
#include <sys/types.h>  
#include <sys/ipc.h>  
#include <sys/sem.h>  
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>

/*信号量的P操作*/  
void p(int semid)  
{  
    struct sembuf sem_p;  
    sem_p.sem_num=0;  
    sem_p.sem_op=-1;  
    if(semop(semid,&sem_p,1)==-1)  
        printf("p operation is fail/n");          
}  

/*信号量的V操作*/  
void v(int semid)  
{  
    struct sembuf sem_v;  
    sem_v.sem_num=0;  
    sem_v.sem_op=1;  
    if(semop(semid,&sem_v,1)==-1)  
        printf("v operation is fail/n");  
}  
  
int main()  
{  
    struct People{  
        char name[10];  
        int age;  
    };  
      
    int semid;  
    int shmid;  
    key_t semkey;  
    key_t shmkey;  
    semkey=ftok("server.c",0);  
    shmkey=ftok("client.c",0);  
      
    /*创建共享内存和信号量的IPC*/  
    semid=semget(semkey,1,0666|IPC_CREAT);  
    if(semid==-1)  
        printf("creat sem is fail/n");  
    shmid=shmget(shmkey,1024,0666|IPC_CREAT);  
    if(shmid==-1)  
        printf("creat shm is fail/n");  
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);  
}  
