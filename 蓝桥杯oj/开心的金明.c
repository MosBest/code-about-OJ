#include<stdio.h>


int max(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	return b;
}

int main()
{
	int N=0,m=0;
	scanf("%d %d",&N,&m);
	int dp[m+1][N+1];
	int v[m+1];
	int p[m+1];
	int i=0;
	int j=0;
	v[0]=0;
	p[0]=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",v+i,p+i);
	}
	
	for(i=0;i<m+1;i++)
	{
		dp[0][i]=0;
	}
	
	for(i=1;i<m+1;i++)
	{
		for(j=0;j<N+1;j++)
		{
			if(j<v[i])
			{
				dp[i][j]=dp[i-1][j];
				
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+v[i]*p[i]);
			}
			
		}
		
	}
	
	
	printf("%d",dp[m][N]);
	return 0;
}
