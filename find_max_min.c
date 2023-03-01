//to find the maximum and minimum element using divide and conquer
#include<stdio.h>
#include<stdlib.h>
void main()
{
	int result,n,*arr,i,x;
	printf("\nEnter the number of elements in the array: ");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	printf("\nEnter the elements of the array:");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	printf("\nThe minimum element is: %d",find_min(arr,0,n-1));
	printf("\nThe maximum element is: %d",find_max(arr,0,n-1));	
	printf("\n");
}//end of main
find_max(int *arr,int start,int end){
	int max=arr[0],mid=start+(end-start)/2;
	if(start==end)
	return(arr[start]);
	if(start==end-1)
	return((arr[start]<arr[end])?(arr[end]):(arr[start]));
	int max1=(find_max(arr,start,mid-1));
	int max2=(find_max(arr,mid,end));
	return((max1<max2)?(max2):(max1));
}//end of fn.
find_min(int *arr,int start,int end){
	int min=arr[0],mid=start+(end-start)/2;
	if(start==end)
	return(arr[start]);
	if(start==end-1)
	return((arr[start]<arr[end])?(arr[start]):(arr[end]));
	int min1=(find_min(arr,start,mid-1));
	int min2=(find_min(arr,mid,end));
	return((min1>min2)?(min2):(min1));
}//end of fn.
