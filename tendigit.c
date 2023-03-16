//to find the only ten-digit number where the ith digit gives the frequency of the ith number
#include <stdio.h>
#include <stdbool.h>
bool isValid(int* arr);
int counting(int* arr, int index);
void changeArray(int*num);
int counting(int* arr, int x){
    int i,count=0;
    for(i=0;i<10;i++){
        if(arr[i]==x)
        count++;
    }
    return(count);
}//end of fn.
bool isValid(int* arr){
    int i;
    for(i=0;i<10;i++)
    if(arr[i]!=counting(arr,i))
    return(false);
    return(true);
}//end of fn.
void changeArray(int* num)
{
    while(!isValid(num))
    {
        int i;
        for(i=0;i<10;i++)
        num[i]=counting(num,i);
    }//end of while loop
}//end of fn.
void main()
{
    int i;
    int num[]={0,0,0,0,0,0,0,0,0,0};
    changeArray(num);
    printf("\nThe required number is: ");
    for(i=0;i<10;i++)
    printf(" %d",num[i]);
    printf("\n");
}//end of main