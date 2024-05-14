#include<stdio.h>
#include<unistd.h>
#include<signal.h>
//void sigint_handler(int sig)
int main()
{
int ret,pid,signalnumber;
printf("enter by pid,signalnumber");
scanf("%d %d",&pid,&signalnumber);
ret=kill(pid,signalnumber);
if(ret==0)
{
printf("success");

}
else
{
printf("fail");
_exit(-1);
}
return 0;
}
