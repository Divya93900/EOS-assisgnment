#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	int ret1,ret2,ret3,i,s1,s2,s3;
	ret1=fork();
	if(ret1==0){
		ret2=fork();
		if(ret2==0){
			ret3=fork();
			if(ret3==0){
				for(i=1;i<=5;i++)
				{
					printf("child3:%d\n",i);
					sleep(1);
				}
				_exit(0);
			}
			for(i=1;i<=5;i++)
			{
				printf("child2:%d\n",i);
			//	wait(&s3);
				sleep(1);
			}
			wait(&s3);
			_exit(0);
		}
		for(i=1;i<=5;i++)
		{
			printf("child1:%d\n",i);
		//	wait(&s2);
			sleep(1);
		}
		wait(&s2);
		_exit(0);
	}

	{
//		printf("parent\n");
		wait(&s1);
		printf("parent\n");
	}
}

