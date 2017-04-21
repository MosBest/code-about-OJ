#include<stdio.h> 
#include<malloc.h>
struct point{
	int flag;
	struct point* p;
} ;
int sum(int* G,int i,struct point*q);
int SUM_max(int* F,int* G,int i,struct point*q);

int main(void)
{
	int n=0;
	int i=0,j=0;
	int a[100001][3]={0};
	int b=0; 
	int from=0,to=0;
	struct point* v=0; 
	
	scanf("%d",&n);
	const int m=n;
	struct point q[m+1];
	int F[m+1];
	int G[m+1];
	
	
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i][0]);
		//初始化q[m] 
		q[i].flag=i;
		q[i].p=NULL;
	}
	
	
	for(i=1;i<=n-1;i++)
	{
		scanf("%d %d",&from,&to);
		//构建链表 
		v=(struct point*)malloc(sizeof(struct point)*1);
		v->flag=to;
		v->p=q[from].p;
		q[from].p=v;
		//构建数组 
		a[to][1]=from;
	}
	
	//填写第几层 
	for(i=1;i<=n;i++)
	{
		if(a[i][1]==0)
		{
			a[i][2]=1;
		}
		else
		{
			a[i][2]=a[(a[i][1])][2]+1;
		}
		 
		//存储最大值 
		if(a[i][2]>b)
		{
			b=a[i][2];
		}
	}
	
	for(;b>=1;b--)
	{
		for(i=1;i<=n;i++)
		{
			if(a[i][2]==b)
			{
				if(q[i].p==NULL)//什么i是叶子节点
				{
					F[i]=a[i][0];
					G[i]=0;
				 } 
				else
				{
					F[i]=a[i][0]+sum(G,i,q);
					G[i]=SUM_max(F,G,i,q); 
				}
			}
		}
	}
	
	if(F[1]>G[1])
	{
		printf("%d",F[1]);
	}
	else
	{
		printf("%d",G[1]);
	}
	
		
	/*
	for(i=1;i<=n;i++)
	{
		a[(a[i][1])][2]++;
	}
	*/
	/*
	for(i=1;i<=n;i++) 
	{
		printf("%d %d\n",a[i][0],a[i][1]);
	}
	
	for(i=1;i<=m;i++)
	{
		v=&(q[i]);
		for(;;)
		{
			if(v->p==NULL)
			{
				printf("%d\n",v->flag);
				break;
			}
			
			printf("%d ",v->flag);
			v=v->p;
		}
	}
	*/

	return 0;
}

int sum(int* G,int i,struct point*q)
{
	int num=0;
	struct point* pp=q+i; 
	pp=pp->p;
	for(;pp!=NULL;)
	{
		num=num+G[pp->flag];
		pp=pp->p;
	}
	
	return num;
}

int SUM_max(int* F,int* G,int i,struct point*q)
{
	int num=0;
	struct point* pp=q+i; 
	pp=pp->p;
	for(;pp!=NULL;)
	{
		if(G[pp->flag]>F[pp->flag])
		{
			num=num+G[pp->flag];
		}
		else
		{
			num=num+F[pp->flag];
		}
		pp=pp->p;
	}
	
	return num;
}

