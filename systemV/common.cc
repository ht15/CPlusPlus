#include "common.h"

int sendMsgQueue(int msg_id, int who, char* msg){
    struct Message buf;
    buf.mtype = who;
    strcpy(buf.mtext, msg);

    if(msgsnd(msg_id, (void*)&buf, sizeof(buf.mtext), 0) < 0)
    {
        return -1;
    }
    return 0;
}

int recvMsgQueue(int msg_id, int recvType, char out[]){
    struct Message buf;
    int size=sizeof(buf.mtext);
    if(msgrcv(msg_id, (void*)&buf, size, recvType, 0) < 0)
    {
        return -1;
    }

    strncpy(out, buf.mtext, size);
    out[size] = 0;
    return 0;
}
