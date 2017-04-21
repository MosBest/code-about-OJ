/*#include<stdio.h> 

int main()
{
	int m=0,n=0;
	int i=0,j=0;
	scanf("%d%d",&m,&n);
	int dp[m+1][n+1];
	
	//边界状态的值 
	dp[0][0]=0;
	for(i=1;i<=m;i++)
	{
		dp[i][0]=1;
	}
	for(j=1;j<=n;j++)
	{
		dp[0][j]=0;
	}
	
	//其他状态的值
	for(i=1;i<=m;i++) 
	{
		for(j=1;j<=n;j++)
		{
			if(i<j)//i<j
			{
				dp[i][j]=0;
			}
			else
			{
				if(i==j)//i==j
				{
					dp[i][j]=dp[i][j-1];
				}
				else//i>j
				{
					dp[i][j]=dp[i-1][j]+dp[i][j-1];
				}	
			}	 
		}
	}
	printf("%d",dp[m][n]);
	return 0;
}
*/
