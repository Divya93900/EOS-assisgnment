#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
int ret,i,s;
for( i=0;i<5;i++)
{
ret=fork();
if(ret==0)
{
for(int j=0;j<5;j++)
{
printf("child1:%d\n",j);
printf("child:pid=%d\n",getpid());
sleep(1);
}
_exit(0);
}
}

for(i=0;i<5;i++)
{
wait(&s);
printf("child exit:%d\n",WEXITSTATUS(s));
}
return 0;
}

