#include<stdio.h>

int main()
{
	int K=0,L=0;
	long long int a=0;
	long long int c[100][100]={0};
	int i=0,j=0,k=0;
	//int c[L][K]={0};
	scanf("%d %d",&K,&L);
	
	for(j=0;j<K;j++)
	{
		c[0][j]=0;
	}
	
	for(j=0;j<K;j++)
	{
		if((j==0) || (j==1) || (j==K-1))
		{
			c[1][j]=K-2;
		}
		else
		{
			c[1][j]=K-3;
		}
		
	}
	
	for(i=2;i<L;i++)
	{
		for(j=0;j<K;j++)
		{
			for(k=0;k<K;k++)
			{
				if(k!=(j+1) && k!=(j-1))
				{
					c[i][j]+=c[i-1][k];
					c[i][j]=c[i][j]%1000000007;
				}
				
				
			}
		}
		
	}
	for(j=0;j<K;j++)
	{
		a=a+c[L-1][j];
		a=a%1000000007;
	}
	
	printf("%I64d",a);
	return 0;
}
