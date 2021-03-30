#include "common.h"

int main(int argc, const char* argv[]){
    key_t msgkey;
    int msgid;
    msgkey = ftok("test_queue", 0x6666);
    msgid = msgget(msgkey, 0666|IPC_CREAT);
    char buf[1024] = {0};
    for(int i=0;i<10;i++){
        char tmpstr[100];
        sprintf(tmpstr, "client: %d", i);
        strcpy(buf, tmpstr);
        sendMsgQueue(msgid, C_TYPE, buf);
        recvMsgQueue(msgid, S_TYPE,buf);
        printf("rec from server: %s\n", buf);
    }
    return 0;

}
