#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<pthread.h>
#include<stdlib.h>

void* thread_func(void* param)
{
int *arr=(int*)param;
   int i, j, min_idx,*ret,n=10,temp;

    // One by one move the boundary of the unsorted subarray
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in the unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element

        temp=arr[min_idx];
        arr[min_idx]= arr[i];
        arr[i]=temp;
 }
ret=(int*)malloc(sizeof(arr));
ret=arr;
return ret;
}

int main()
{
int i,ret,*result;
pthread_t t1;
int arr[10]={100,90,80,75,60,55,42,10,20,10};
pthread_create(&t1,NULL,thread_func,arr);
printf("press enter to get sorted array ");
getchar();
pthread_join(t1,(void **)&result);
for(int i=0;i<10;i++)
{
printf("%d\n",arr[i]);
sleep(1);
}
return 0;
}
