#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	int ret,s,i,k;
	i=1;
	while(1)
	{
		ret=fork();
		if(ret==0)
		{
			for(int j=1;j,3;j++)
			{
				printf("childtask:%d\n",j);
				_exit(0);
			}
		}
		else if(ret==-1)
		{	printf("fail");
		break;
		}
		else
		{
			i++;
			printf("child count:%d\n",i);
		}
	}
	for(k=1;k<=i;k++)
		wait(&s);
}
