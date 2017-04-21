#include<stdio.h> 

int max(int a, int b);

int main()
{
	int n=0;
	int i=0,j=0;
	scanf("%d",&n);
	int a[n+1][n+1];//���ڴ洢��������� 
	int dp[n+1][n+1];
	
	//��������
	for(i=1;i<=n;i++) 
	{
		for(j=1;j<=i;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	//�߽�״̬��ֵ dp[n][i]=a[n][i]
	for(j=1;j<=n;j++)
	{
		dp[n][j]=a[n][j];
	}
	
	//����״̬��ֵ
	for(i=n-1;i>=1;i--)
	{
		for(j=1;j<=i;j++)//ֻ�� ����i>=j�������i<j���ÿ���
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
