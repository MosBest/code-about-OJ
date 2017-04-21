//�㷨˼�룺�����㷨  ����bfsʵ��
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
bool visited[101][101][101];//���� ��֦,visited[5][3][7]=true������ǵ�1������װ5��λˮ�� 
							//��2������װ3��λˮ����3������װ7��λˮ�Ѿ����ʹ���
							//�Ժ����������������ѹ������� 

void Pour(int i,int k,node* next)//��i�����Ӹ�k��ˮ��������洢��next�� 
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
	visited[start.w[1]][start.w[2]][start.w[3]]=true;//��Ȼ������һ�� 
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
		//pr�еı��ӵ�ˮ��������洢��next��
		//����6�������1����2,3 ��2����1,3��3����1,2 ���������������
		for(int i=0;i<3;i++) 
		{
			for(int j=1;j<3;j++)
			{
				int k=(i+j)%3;//��ʽ�ӿ��Ա�֤��i+1Ϊ1ʱ��k+1ȡ2,3 
										//i+1=2ʱ,k+1=1,3;i+1=3ʱ,k+1=1,2 
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
