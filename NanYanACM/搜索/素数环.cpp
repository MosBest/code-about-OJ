#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int n;
int prime[40]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0};
int a[30];
int visited[30];
int flag=0;
void DFS(int lest)
{
	if(lest>n)
		return;
	
	if(lest==n)
	{
		if(prime[a[n]+1]==1)
		{
			flag=1;
			for(int i=1;i<=n;i++)
				printf("%d ",a[i]);
			printf("\n");
		}
		
	}
	
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0 && prime[a[lest]+i]==1)
		{
			a[lest+1]=i;
			visited[i]=1; 
			DFS(lest+1);
			visited[i]=0;
			
		}
		
	}
	
}
int main()
{
	int i=0;
	while(scanf("%d",&n)!=EOF && n!=0)
	{
		
		memset(visited,0,sizeof(visited));
		memset(a,0,sizeof(a));
		i++;
		flag=0;
		printf("Case %d:\n",i);
		a[1]=1;
		visited[1]=1;
		if(n==1)
		{
			printf("%d\n",1);
			continue;
		}
		if(n%2==0)
			DFS(1);
		
		if(flag==0)
			printf("No Answer\n");
	}
	return 0;
}
