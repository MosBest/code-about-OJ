#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

typedef struct{
	int x;
	int y;
}node;
int N;
int W,H;
int a[1440][1440];

int way[4][4]={{-1,0},{0,1},{1,0},{0,-1}};

void BFS(int x,int y)
{
	queue<node> q;
	node head;
	head.x=x;
	head.y=y;
	q.push(head);
	while(!q.empty())
	{
		node pr=q.front();
		q.pop();
		if(a[pr.x][pr.y]!=0)
		{
			a[pr.x][pr.y]=0;
			node next;
			for(int i=0;i<4;i++)//4个方向
			{
				next.x=pr.x+way[i][0];
				next.y=pr.y+way[i][1];
				if( next.x<=H+1 && next.x>=0 && next.y<=W+1 && next.y>=0 && a[next.x][next.y]!=0)
				{
					q.push(next);
				}
			}	
		}
	}
	
	for(int i=1;i<=H;i++)
	{
		for(int j=1;j<=W;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	
}

int main()
{
	scanf("%d",&N);
	
	for(int i=0;i<N;i++)
	{
		
		memset(a,1,sizeof(a));//将矩阵的外围全部赋值为1
		scanf("%d%d",&W,&H);
		for(int j=1;j<=H;j++)
		{
			for(int k=1;k<=W;k++)
			{
				scanf("%d",&a[j][k]);
			}
		}
		//从0，0 开始，这样就不会一开始就遇到0了 
		BFS(0,0);
	}
	return 0;
}
