#include<iostream>
#include<cstdio>
#include<cstring>
 
using namespace std;
int a[1010][1010];//用邻接矩阵来存储图 
int flag=0;
int P,Q;
void DFS(int han)
{
	if(han>P)
		return;
	
	for(int j=1;j<=P;j++) 
	{
		if(a[han][j]==1)
		{
			a[han][j]=0;
			DFS(j);
		}
	}
	
}
int main()
{
	int N;
	scanf("%d",&N);
	for(int k=0;k<N;k++)
	{
		
		scanf("%d%d",&P,&Q);//P是点，Q是边 
		memset(a,0,sizeof(a));
		int A,B;
		for(int j=0;j<Q;j++)
		{
			scanf("%d%d",&A,&B);
			a[A][B]=1;
			a[B][A]=1;
		}
		//判断奇点 
		int c=0;
		for(int i=1;i<=P;i++)
		{
			int num=0;
			for(int j=1;j<=P;j++)
			{
				if(a[i][j]==1)
					num++;
			}
			if(num%2==1)
				c++;
		}
		flag=0;
		if(c<=2)//度数为奇数的点的个数小于等于2
		{
			DFS(1);//再判断该图是否连通 
			for(int i=1;i<=P;i++)
			{
				for(int j=1;j<=P;j++)
				{
					if(a[i][j]==1)
						flag=-1;
				}
			}
			if(flag==-1)
				flag=0;
			else
				flag=1;
		}
		
		if(flag==0)
			printf("No\n");
		else
			printf("Yes\n");
		
	}
	return 0;
}
