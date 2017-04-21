#include<stdio.h> 

long long int max(long long int a, long long int b)
{
	if(a>b)
	{
		return a;
	}
	else
	return b;
}
int main()
{
	int N=0,K=0;
	int i=0,j=0,k=0;
	
	scanf("%d%d",&N,&K);
	long long int dp[N+1][K+1];
	int a[N+1];
	int sum[N+1];
	sum[0]=0;
	for(i=1;i<=N;i++)
	{
		scanf("%d",a+i);
		sum[i]=0;
	}
	
	for(i=1;i<=N;i++)
	{
		sum[i]=sum[i-1]+a[i];
		
	}
	
	for(i=0;i<=N;i++)
	{
		for(j=0;j<=K;j++)
		{
			dp[i][j]=0;
		}
	}
	
	//边界条件
	for(i=0;i<=K;i++)
	{
		dp[0][i]=0;
	
		dp[1][i]=a[1];
	}
	
	for(i=1;i<=N;i++)
	{
		dp[i][0]=sum[i];
	}
		
	//动态规划
	for(i=2;i<=N;i++) 
	{
		for(j=1;j<=K;j++)
		{
			if(j>i-1)
			{
				dp[i][j]=dp[i][j-1]; 
			}
			for(k=1;k<=i;k++)
			{
				
				dp[i][j]=max(dp[i][j],dp[k-1][j-1]*(sum[i]-sum[k-1]));		
				
			}
		}
	}
	
	printf("%I64d",dp[N][K]);

	
	
	return 0;
}
