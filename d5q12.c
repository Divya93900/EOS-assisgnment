#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	int fd,fd1,cnt;
	int arr[27];
	fd=open("/tmp/ass",O_RDONLY);
	if(fd<0)
	{
		perror("failed");
		_exit(8);
	}
	printf("waiting for data\n");

	cnt=read(fd,arr,sizeof(arr));

	for(int i=1;i<3;i++)
		printf("read from :%d\n",arr[i]);
	//close(fd);


	//sending sum{
	fd1=open("/tmp/sum",O_WRONLY);
	if(fd1<0)
	{
		perror("open failed\n");
		_exit(7);
	}
	arr[3]=arr[1]+arr[2];
	//printf("sum:%d/n"&sum);
	cnt=write(fd1,arr,sizeof(arr));
	printf("returing sum %d\n",arr[3]);
	close(fd1);
	close(fd);
	return 0;
}


