//to implement fractional knapsack
#include<stdio.h>
#include<stdlib.h>
void main(){
	int i,j,cap,n,*weights,*values,ti;
	float *ratios,answer=0.0,tf;
	printf("\nEnter the number of items in the knapsack:");
	scanf("%d",&n);
	printf("\nEnter the capacity of knapsack:");
	scanf("%d",&cap);
	ratios=(float*)malloc(n*sizeof(float));
	weights=(int*)malloc(n*sizeof(int));
	values=(int*)malloc(n*sizeof(int));
	printf("\nEnter the values:");
	for(i=0;i<n;i++)
	scanf("%d",&values[i]);
	printf("\nEnter the weights:");
	for(i=0;i<n;i++)
	scanf("%d",&weights[i]);
	for(i=0;i<n;i++)
	ratios[i]=(float)values[i]/(float)weights[i];
	for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
	if(ratios[i]<ratios[j]){
		tf=ratios[i];
		ratios[i]=ratios[j];
		ratios[j]=tf;
		ti=weights[i];
		weights[i]=weights[j];
		weights[j]=ti;
		ti=values[i];
		values[i]=values[j];
		values[j]=ti;
	}//end of if block
	for(i=0;i<n;i++){
		if(weights[i]<=cap){
			answer+=values[i];
			cap-=weights[i];
		}//end of if block
		else{
			answer+=(cap*ratios[i]);
			break;
		}//end of else block
	}//end of for loop
	printf("\nThe answer for the given fractional knapsack problem is: %f\n",answer);
}//end of main
