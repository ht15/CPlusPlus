#include "comm.h"

int main()
{
    int msgid = getMsgQueue();

    char buf[1024] = {0};
    while(1)
    {
        printf("Please Enter# ");
        fflush(stdout);
        scanf("%s", buf);
        sendMsgQueue(msgid, CLIENT_TYPE, buf);
        if(strcasecmp("quit", buf) == 0)
            break;
        printf("send done, wait recv...\n");

        recvMsgQueue(msgid, SERVER_TYPE, buf);
        printf("server# %s\n", buf);
    }
    return 0;
}
