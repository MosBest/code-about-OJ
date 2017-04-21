#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>

using namespace std;

typedef struct{
	int x;
	int y;
	int c;
}node;
int a[100][100];
int visited[100][100];

int d[5][2]={{0,0},{0,1},{1,0},{0,-1},{-1,0}};

void dfs(int m,int n)
{
	
	int p,q;
	int num=0;
	stack<node> mystack;
	node fr,next;
	memset(visited,0,sizeof(visited));

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]==1&&visited[i][j]<4)
			{
				
				next.x=i;
				next.y=j;
				
				
				mystack.push(next);
				num++;
			
			}
			while(!mystack.empty())
			{
			
				next=mystack.top();
				if(visited[next.x][next.y]<4)
				{
					visited[next.x][next.y]++;
					fr.x=next.x+d[visited[next.x][next.y]][0];
					fr.y=next.y+d[visited[next.x][next.y]][1];
				}
				else
				{
					mystack.pop();
					continue;
				}
						
				while((fr.x<m && fr.x>=0 && fr.y>=0 && fr.y<n) && a[fr.x][fr.y]==1 && visited[fr.x][fr.y]<4)
				{
					mystack.push(fr);
					visited[fr.x][fr.y]++;
					next=fr;
					fr.x=next.x+d[visited[next.x][next.y]][0];
					fr.y=next.y+d[visited[next.x][next.y]][1];
				}
					
			}
		}
	}
	printf("%d\n",num);
	return;
}

int main()
{
	int N;
	int k;
	int m,n;
	scanf("%d",&N);
	for(k=1;k<=N;k++)
	{
		scanf("%d%d",&m,&n);
	
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&a[i][j]);
			
		dfs(m,n);
	}
	return 0;
}
