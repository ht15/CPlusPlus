#include <stdio.h>  
#include <stdlib.h>
#include <sys/types.h>  
#include <sys/ipc.h>  
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>

const long S_TYPE=1;
const long C_TYPE=2;


struct Message {
    long mtype;
    char mtext[1024];
};

int sendMsgQueue(int msg_id, int who, char* msg);
int recvMsgQueue(int msg_id, int recvType, char out[]);
