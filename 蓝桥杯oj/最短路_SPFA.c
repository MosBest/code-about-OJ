#include<stdio.h> 
#include<malloc.h>

struct node{
	int flag;
	int wight;
	struct node* p;
};

struct shuzhu{
	int d;
	int f;
	struct node* p;
};

void INITIALIZE_SOURCE(struct shuzhu*a,int n);
void SPFA(struct shuzhu* a,int n);

int main()
{
	int n=0,m=0;
	int u=0,v=0,l=0;
	int i=0,j=0;
	struct node* pp=0;
	scanf("%d%d",&n,&m);
	struct shuzhu a[n+1];
	
	//初始化 邻接表 
	INITIALIZE_SOURCE(a,n);
	
	//存储输入数据到链接表中 
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&u,&v,&l);
		pp=(struct node*)malloc(sizeof(struct node)*1);
		pp->flag=v;
		pp->wight=l;
		pp->p=a[u].p;
		a[u].p=pp;
	}
	/* 
	//检验存储代码的正确性 
	for(i=1;i<=m;i++)
	{
		printf("[%d %d]  ",a[i].d,a[i].f);
		pp=a[i].p;
		for(;pp!=NULL;)
		{
			printf("[%d %d]  ",pp->flag,pp->wight);
			pp=pp->p;
		}
		
		printf("\n");
	}
	*/ 
	
	//BELLMAN算法，计算 1号点到其他点的最短路 
	SPFA(a,n);
	
	//打印结果
	for(i=2;i<=n;i++)
	{
		printf("%d\n",a[i].d);
	}
	 
	return 0;
}

void INITIALIZE_SOURCE(struct shuzhu* a,int n)
{
	int i=1;
	
	a[1].d=0;
	a[1].f=0;
	a[1].p=NULL;
	
	for(i=2;i<=n;i++)
	{
		a[i].d=10000000;
		a[i].f=-1;
		a[i].p=NULL;
	}
	
	return;
}

void SPFA(struct shuzhu* a,int n)
{
	int i=-1;
	int j=0;
	struct node* q=0;
	int Q[200000]={0};
	
	Q[0]=1;
	j=j+1;
	while(i+1 != j)
	{
		q=a[Q[i+1]].p;//Q出一个数 
		i=i+1;
		while(q!=NULL)
		{
			if(a[q->flag].d > a[Q[i]].d + q->wight)
			{
				a[q->flag].f=j;
				a[q->flag].d=a[Q[i]].d+q->wight;
				Q[j]=q->flag;//Q进入一个数 
				j=j+1;
			}
			
			q=q->p;
		}
	}
	
	

	return;
}
