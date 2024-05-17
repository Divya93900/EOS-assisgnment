#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
int fd1, fd,cnt;
int arr[27];
fd=open("/tmp/ass",O_WRONLY);
if(fd<0)
{
perror("open() failed");
_exit(8);
}
printf("enter array\n");

for(int i=1;i<3;i++)
{
scanf("%d",&arr[i]);
}
cnt=write(fd,arr,sizeof(arr));
printf("written in fifo:%d\n",cnt);
//close(fd);



fd1=open("/tmp/sum",O_RDONLY);
if(fd1<0)
{
perror("open()failed");
_exit(7);
}

cnt=read(fd1,arr,sizeof(arr));
printf("result %d\n",arr[3]);
close(fd1);
close(fd);
return 0;
}
