#include<stdio.h>
#include<signal.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<unistd.h>
//int ret,num1,num2,s2;

int main()
{
int res,ret,num1,num2,n1,n2,r,s1;
int arr1[30],arr2[34];
ret=pipe(arr1);
ret=pipe(arr2);
ret=fork();
if(ret==0)
{
close(arr1[0]);
close(arr2[1]);
printf("child enter 2 number");
scanf("%d%d",&num1,&num2);
write(arr1[1],&num1,sizeof(num1));
write(arr1[1],&num2,sizeof(num2));
read(arr2[0],&res,sizeof(res));
printf("result:%d\n",res);
close(arr2[0]);
close(arr1[1]);
}
else{
close(arr1[1]);
close(arr2[0]);
read(arr1[0],&n1,sizeof(n1));
read(arr1[0],&n2,sizeof(n2));
r=n1+n2;
write(arr2[1],&r,sizeof(r));
close(arr2[1]);
close(arr1[0]);
wait(&s1);
}
}
