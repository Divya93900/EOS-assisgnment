#include<stdio.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/wait.h>
#define MQ_KEY 0x12309
typedef struct msg{
long type;
int a1;
int b1;
}msg_t;
typedef struct msg1{
long type;
int sum;
}msg1_t;

int main()
{
int mqid,ret,s,m1,m2,m3;
mqid=msgget(MQ_KEY,IPC_CREAT|0600);
if(mqid<0)
{
perror("failed");
_exit(1);
}
ret=fork();
if(ret==0)
{
msg_t m1;
m1.type=1;
//m1.a1=1;
//m1.b1=1;
printf("sender send a a1,b1\n");
scanf("%d %d",&m1.a1,&m1.b1);
ret=msgsnd(mqid,&m1,sizeof(m1)-sizeof(long),0);
printf("sender:messege sent:%d\n",ret);
msg1_t m4;
ret=msgrcv(mqid,&m4,sizeof(m4)-sizeof(long),90,0);
printf("messege recieved :%d\n",m4.sum);
}

else{
msg_t m2;

printf("receiver:waiting for the message\n");
ret=msgrcv(mqid,&m2,sizeof(m2)-sizeof(long),1,0);
//ret=msgrcv(mqid,&m3,sizeof(m3.sum),1,0);
printf("receiver:message received:%d %d %d \n",ret,m2.a1,m2.b1);
msg1_t m3;
m3.sum=m2.a1 + m2.b1;
m3.type=90;
ret=msgsnd(mqid,&m3,sizeof(m3)-sizeof(long),0);
//printf("receiver : message received:%d--%d\n",ret,m3.sum);
wait(&s);
}
return 0;
}

