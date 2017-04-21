#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
typedef struct{
	int x;
	int y;
	int step;
}node;

int A[9][9]={ 1,1,1,1,1,1,1,1,1,
			 1,0,0,1,0,0,1,0,1,
			 1,0,0,1,1,0,0,0,1,
			 1,0,1,0,1,1,0,1,1,
			 1,0,0,0,0,1,0,0,1,
			 1,1,0,1,0,1,0,0,1,
			 1,1,0,1,0,1,0,0,1,
			 1,1,0,1,0,0,0,0,1,
			 1,1,1,1,1,1,1,1,1};
bool B[9][9];
int ans=0x3f3f3f3f;
int e[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int a,b,c,d;

void bfs(int a,int b,int c,int d)
{
	int ans=0x3f3f3f3f;
	queue<node> Q;

	memset(B,0,sizeof(B));
	node pr,next;
	pr.x=a;
	pr.y=b;
	pr.step=0;
	Q.push(pr);
	
	while(!Q.empty())
	{
		pr=Q.front();
		Q.pop();
		for(int i=0;i<4;i++)
		{
			next.x=pr.x+e[i][0];
			next.y=pr.y+e[i][1];
			next.step=pr.step+1;
			
			if(A[next.x][next.y]==0 && B[next.x][next.y]==false)
			{
				B[next.x][next.y]=true;
				Q.push(next);
			}
			
			if(next.x==c && next.y==d)
			{
				ans=min(ans,next.step);
			}
		}
	}
	printf("%d\n",ans);
}


int main()
{
	int n=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a==c&&b==d)
		{
			printf("%d\n",0);//ÒªÅÐÖØ 
			continue;
		}
		bfs(a,b,c,d);
	}
	return 0;
}
 
