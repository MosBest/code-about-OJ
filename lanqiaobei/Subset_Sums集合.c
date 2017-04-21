#include<stdio.h>

int max(int a , int b)
{
	if(a>b)
	{
		return a;
	}
	return b;
}

int main()
{
	int N=0;
	scanf("%d",&N);
	int m=(1+N)*N/2;
	int dp[N+1][m+1];
	int i=0,j=0;
	for(i=0;i<m+1;i++)
	{
		if(i==N ||i==0)
		{
			dp[N][i]=1;
		}
		else
		{
			dp[N][i]=0;
		}
	}
	
	for(i=N-1;i>=1;i--)
	{
		for(j=0;j<m+1;j++)
		{
			if(j<i)
			{
				dp[i][j]=dp[i+1][j];
			}
			else
			{
				dp[i][j]=dp[i+1][j-i]+dp[i+1][j];
			}
			
		}
	}
	for(i=0;i<m+1;i++)
	printf("%d ",dp[1][m]);
	return 0;
}
