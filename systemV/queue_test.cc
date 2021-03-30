 #include <sys/msg.h>
 #include <unistd.h>
 #include <sys/types.h>
 #include <stdio.h>
 #include <string.h>

 struct Mymsg {
  long mtype;
  char mtext[24];
 };

 int main()
 {
  int msqid;
  Mymsg msg,buff;
  msqid=msgget(IPC_PRIVATE,IPC_CREAT|IPC_EXCL|0666);

  if(msqid==-1){
  perror("FAiled to create message queue\n");
  }
  else{
  printf("Message queue id:%u\n",msqid);
  }
  msg.mtype=1;
  strcpy(msg.mtext,"This is a message");
  if(msgsnd(msqid,&msg,sizeof(msg.mtext),0)==-1){
   perror("msgsnd failed:");
  }
  else{
   printf("Message sent successfully\n");
  }
 //ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp,int msgflg);

  // msgrcv(msqid,buff.mtext,sizeof(msg.mtext),1,0); This was error
  msgrcv(msqid,&buff,sizeof(msg.mtext),1,0);  // This is correct (Thanks to Erik)
  printf("The message received is: %s\n",buff.mtext);
 }
