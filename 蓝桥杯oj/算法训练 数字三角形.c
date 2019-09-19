#include<stdio.h> 

int max(int a, int b);

int main()
{
	int n=0;
	int i=0,j=0;
	scanf("%d",&n);
	int a[n+1][n+1];//用于存储输入的数据 
	int dp[n+1][n+1];
	
	//输入数据
	for(i=1;i<=n;i++) 
	{
		for(j=1;j<=i;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	//边界状态的值 dp[n][i]=a[n][i]
	for(j=1;j<=n;j++)
	{
		dp[n][j]=a[n][j];
	}
	
	//其他状态的值
	for(i=n-1;i>=1;i--)
	{
		for(j=1;j<=i;j++)//只用 考虑i>=j的情况，i<j不用考虑
		{
			dp[i][j]=a[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
		}
	}
	printf("%d",dp[1][1]);
	return 0;
}

int max(int a, int b)
{
	if(a>b)
	{
		return a;
	}
	return b;
}
