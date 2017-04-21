#include<iostream>
#include<cstdio>
#include<cstring>

int n,k;
int a[30];
bool visited[30];
int sum=0;
int flag=0;
void DFS(int i)//从i开始选，但是i还没有被选 
{
	if(i>n || flag==1)
		return;
	
		
	for(int j=i;j<=n;j++)
	{
		visited[j]=true;
		 if(k==sum+a[j] && flag==0 )
		{
			flag=1;
			visited[j]=true;
			printf("YES\n");
			for(int p=1;p<=n;p++)
			{
				if(visited[p]==true)
					printf("%d ",a[p]);
			}
			printf("\n");
			return;
		}
		else if(k!=sum+a[j] && flag==0 )
		{
			sum+=a[j];
			visited[j+1]=true;
			DFS(j+1);
			sum-=a[j];
			visited[j+1]=false;
		}
		visited[j]=false;
	}
	
	
	return;	
}

int main()
{
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",a+i);
		}
		
		memset(visited,false,sizeof(visited));
		sum=0;
		flag=0;
		DFS(1);
		if(flag==0)
			printf("NO\n");
	}
	
	return 0;
}
