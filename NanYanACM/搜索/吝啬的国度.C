#include<stdio.h> 
#include<malloc.h>
struct node{
	int i;
	struct node* p;
};

struct head{
	int f;
	int flag;
	struct node* p;
};

void init(int* a);
void push(int* a,int S);
int pop(int* a);

int main()
{
	int M,N,S;
	int u,v;
	int i=0,j=0,k=0;
	int* a=0; 
	struct head* h=0; 
	struct node* q=0;
	scanf("%d",&M);
	for(i=1;i<=M;i++)
	{
		scanf("%d%d",&N,&S);
		h=(struct head*)malloc(sizeof(struct head)*(N+1));
		a=(int*)malloc(sizeof(int)*(2*N+1));
		for(j=1;j<=N;j++)
		{
			h[j].flag=0;
			h[j].f=0;
			h[j].p=NULL;
		}
		
		for(j=1;j<=N-1;j++)
		{
			scanf("%d%d",&u,&v);
			q=(struct node*)malloc(sizeof(struct node)*1);
			q->i=v;
			q->p=h[u].p;
			h[u].p=q;
			
			q=(struct node*)malloc(sizeof(struct node)*1);
			q->i=u;
			q->p=h[v].p;
			h[v].p=q;
		}
		h[S].f=-1;
		
		init(a);
		push(a,S);
		k=pop(a);
		while(k!=-1)
		{
			if(h[k].flag!=0)
			{
				k=pop(a);
				continue;
			}
			
			h[k].flag=1;
			q=h[k].p;
			
			while(q!=NULL)
			{
				push(a,q->i);
				if(h[q->i].f==0)
				{
					h[q->i].f=k;
				}
				q=q->p;
			}
			k=pop(a);
		}
		
		for(j=1;j<=N;j++)
		{
			printf("%d ",h[j].f);
		}
		printf("\n");
	}
	
	return 0;
}

void init(int* a)
{
	a[0]=1;
	a[1]=2;
}
void push(int* a,int S)
{
	a[a[1]]=S;
	a[1]++;
}
int pop(int* a)
{
	if(a[0]==a[1]-1)
		return -1;
	
	a[0]++;
	return a[a[0]];
}
