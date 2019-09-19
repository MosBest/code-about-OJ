#include<stdio.h>

int main()
{
	int n=0,m=0;
	int i=0,j=0;
	int u=0,v=0;
	
	scanf("%d%d",&n,&m);
	int a[n+1][m+1];
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			a[i][j]=0;
		}
		
	}
	
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		a[u][i]=1;
		a[v][i]=-1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
//何为关联矩阵？？？
//对于一个无向图G，pxq, p为顶点的个数，q为边数。bij 表示在关联矩阵中点i和边j之间的关系。
//若点i和边j之间是连着的，则bij = 1. 反之，则bij = 0
//行为 点的数目，列为  边的数目 
// 
//int a[1000][1000] 长度调为1000是，就会崩掉
//int a[5][6] 长度不足，不让访问，devc++ 好像自动的检查下标越界了 
//	int a[n+1][m+1]={0}; 这样是错误的，不能够赋值 
