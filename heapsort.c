//to perform heap sort on an user-input array
#include<stdio.h>
#include<stdlib.h>
void maxHeapify(int*,int,int);
void heapsort(int*,int);
void maxHeapify(int* arr,int i,int size)
{
    int max=i,left=(i*2)+1,right=(i*2)+2,temp;
    if(left<size && arr[left]>arr[max])
    max=left;
    if(right<size && arr[right]>arr[max])
    max=right;
    if(i!=max)
    {
        temp=arr[i];
        arr[i]=arr[max];
        arr[max]=temp;
        maxHeapify(arr,max,size);
    }//end of if block
}//end of fn.
void heapsort(int* arr,int size)
{
    int i,temp;
    //converting the array to a max heap
    for(i=size/2-1;i>=0;i--)
    maxHeapify(arr,i,size);
    for(i=size-1;i>=0;i--)
    {
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        maxHeapify(arr,0,i);
    }//end of for loop
}//end of fn.
void main()
{
    int n,*arr,i;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array separated by spaces: ");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printf("The user-input array is as follows: ");
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
    printf("\n");
    heapsort(arr,n);
    printf("The sorted array is as follows: ");
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
    free(arr);
}//end of main
