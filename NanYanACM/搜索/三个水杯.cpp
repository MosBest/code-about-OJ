//算法思想：回溯算法  利用bfs实现
#include<iostream> 
#include<cstdio>
#include<queue>
#include<cstring> 

using namespace std;

typedef struct{
	int w[4];
	int step;
}node;

int N;
int V[4],E[4];
bool visited[101][101][101];//用于 剪枝,visited[5][3][7]=true用来标记第1个杯子装5单位水， 
							//第2个杯子装3单位水，第3个杯子装7单位水已经访问过，
							//以后遇到这种情况不用压入队列了 

void Pour(int i,int k,node* next)//第i个杯子给k倒水，将结果存储在next中 
{
	if(next->w[i] <= V[k] - next->w[k])
	{
		next->w[k]=next->w[i]+next->w[k];
		next->w[i]=0;
		
	}
	else
	{
		next->w[i]=next->w[i]-(V[k] - next->w[k]);
		next->w[k]=V[k];
	}
	return;
}

void BFS()
{
	queue<node> q;
	node start,pr;
	memset(visited,false,sizeof(visited));
	start.step=0;
	start.w[1]=V[1];
	start.w[2]=0;
	start.w[3]=0;
	visited[start.w[1]][start.w[2]][start.w[3]]=true;//竟然忘了这一步 
	q.push(start);
	while(!q.empty())
	{
		pr=q.front();
		q.pop();
		if(pr.w[1]==E[1] && pr.w[2]==E[2] && pr.w[3]==E[3])
		{
			printf("%d\n",pr.step);
			return; 
		}
		node next;
		//pr中的杯子倒水，将结果存储在next中
		//共有6种情况，1倒给2,3 ，2倒给1,3，3倒给1,2 ，所以有下面代码
		for(int i=0;i<3;i++) 
		{
			for(int j=1;j<3;j++)
			{
				int k=(i+j)%3;//此式子可以保证当i+1为1时，k+1取2,3 
										//i+1=2时,k+1=1,3;i+1=3时,k+1=1,2 
				next=pr;
				Pour(i+1,k+1,&next);
				next.step=next.step+1;
				if(!visited[next.w[1]][next.w[2]][next.w[3]])
				{
					visited[next.w[1]][next.w[2]][next.w[3]]=true;
					q.push(next);
				}	
			}
		}
	}
	printf("%d\n",-1);
	return; 
}

int main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d%d%d",&V[1],&V[2],&V[3]);
		scanf("%d%d%d",&E[1],&E[2],&E[3]);
		BFS();
	}
	return 0;
}
