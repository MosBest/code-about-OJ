#include<iostream>
#include<cstdio>
using namespace std;
int N,Q;

int main()
{
	scanf("%d%d",&N,&Q);
	int a[N+1];
	int dp[N+1][N+1][2];//数组开的太大，不能用啊！在自己的电脑都跑不起来 
	for(int i=1;i<=N;i++) 
		scanf("%d",a+i);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<i;j++)
		{
			dp[i][j][0]=0;
			dp[i][j][1]=0;
		}
	}
	
	for(int i=1;i<=N;i++)
	{
			dp[i][i][0]=a[i];
			dp[i][i][1]=a[i];
	}
	
	for(int i=1;i<=N;i++)
	{
		for(int j=i+1;j<=N;j++)
		{
			dp[i][j][0]=min(dp[i][j-1][0],a[j]);
			dp[i][j][1]=max(dp[i][j-1][0],a[j]);
		}
	}
	
	int m,n;
	for(int i=0;i<Q;i++)
	{
		scanf("%d%d",&m,&n);
		printf("%d\n",dp[m][n][1]-dp[m][n][0]);
	}
	
	return 0; 
}
