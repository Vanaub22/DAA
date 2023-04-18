//to determine the most efficient way to multiply matrices i.e. to minimize operations
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int minimum_of(int a,int b){
    return(a<b?a:b);
}//end of function
int memoization(int** dp,int orders[],int i,int j){
    int k;
    if(i==j)
    return 0;
    if(dp[i][j]!=-1)
    return(dp[i][j]);
    dp[i][j]=INT_MAX;
    for(k=i;k<j;k++)
    dp[i][j]=minimum_of(dp[i][j],memoization(dp,orders,i,k)+memoization(dp,orders,k+1,j)+orders[i-1]*orders[k]*orders[j]);
    return(dp[i][j]);
}//end of function
void main(){
    int n,*orders,r,c,i,j,**dp;
    printf("Enter the number of matrices to be multiplied (one less than the number of values in the matrix chain): ");
    scanf("%d",&n);
    orders=(int*)malloc((n+1)*sizeof(int));
    dp=(int**)malloc((n+1)*sizeof(int*));
    for(i=0;i<=n;i++)
    dp[i]=(int*)malloc((n+1)*sizeof(int));
    for(i=0;i<=n;i++)
    for(j=0;j<=n;j++)
    dp[i][j]=-1;
    printf("Enter the values in the matrix chain: ");
    for(i=0;i<=n;i++)
    scanf("%d",&orders[i]);
    printf("The matrix chain is as follows: <");
    for(i=0;i<n;i++)
    printf("%d,",orders[i]);
    printf("%d>",orders[n]);
    printf("\nThe minimum number of multiplications required are: %d\n",memoization(dp,orders,1,n));
}//end of main