//你永远不知道你当前的差值是不是最小，所以你要遍历所有的情况 
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int N;
int W[30];
bool visited[30];
int ans;//ans用于记录当前的最小值 
int sum=0;
int SUM=0;

void kuaipai(int l,int r)
{
	int i=l,j=l;
	int x=W[r];
	int y=0;
	if(l>=r)
		return;
	for(int i=l;i<=N;i++)
	{
		if(W[i]<x)
		{
			y=W[i];
			W[i]=W[j];
			W[j]=y;
			
			j++;
		}
	}
	
	y=W[r];
	W[r]=W[j];
	W[j]=y;
	
	kuaipai(l,j-1);
	kuaipai(j+1,r);
	
}

void DFS(int i)
{
	if(i>N)
		return;
	
	
		for(int j=i;j<=N;j++)
	{
		if(sum+W[j]>SUM/2)
			return;
		if(visited[j]==false)
		{
			sum+=W[j];
			if(ans>(SUM-sum)-sum)
				ans=(SUM-sum)-sum;
			visited[j]=true;
			DFS(j+1);
			sum-=W[j];
			visited[j]=false;
		}
	}
	
}
int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		memset(W,0,sizeof(W));
		memset(visited,false,sizeof(visited));
		ans=0x3f3f3f3f;
		sum=0;
		SUM=0;
		for(int i=1;i<=N;i++)
		{
			scanf("%d",W+i);
			SUM+=W[i];
		}
		kuaipai(1,N);
		if(N==1)
			ans=W[1];
		else
			DFS(1); 
		printf("%d\n",ans);
	}
	
	return 0;
}
