#include "common.h"

int main(int argc, const char* argv[]){
    key_t msgkey;
    int msgid;
    msgkey = ftok("test_queue", 0x6666);
    msgid = msgget(msgkey, 0666|IPC_CREAT|IPC_EXCL);
    char buf[1024] = {0};
    for(int i=0;i<10;i++){
        recvMsgQueue(msgid, C_TYPE,buf);
        printf("rec from client: %s\n", buf);
        char tmp_str[100];
        sprintf(tmp_str, "server: %d", i);
        strcpy(buf, tmp_str);
        sendMsgQueue(msgid, S_TYPE, buf);
    }
    msgctl(msgid, IPC_RMID, NULL);
    return 0;

}
