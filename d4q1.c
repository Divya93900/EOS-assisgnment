#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
int main()
{
	int ret,err,s,fd;
	printf("parent started\n");
	ret=fork();
	if(ret==0)
	{
		fd=open("in.txt",O_RDONLY);
		close(0);
		dup(fd);
		close(fd);
		err=execlp("wc","wc",NULL);
		if(err<0)
		{
			perror("exec() failed");
			_exit(1);
		}
	}
	else
		wait(&s);
	printf("parent completed");
	return 0;
}



