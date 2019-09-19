//大部分时间浪费在快排上面 
#include <stdio.h> 

struct vectors{
	int f;
	int weight;
};

struct edge{
	int u;
	int v;//u->v
	int weight;
};

void MST_KRUSKAL(struct edge* e,struct vectors* n,int N,int P);
void kuaipai(struct edge* e,int l, int r);//快排 
int root(int flag,struct vectors* n);//返回u节点的根节点 
int main()
{
	int N=0,P=0;
	int i=0;
	int S=0,E=0,L=0,C=0;
	scanf("%d%d",&N,&P);
	struct vectors n[N+1];
	struct edge e[P+1];
	
	//接收输入数据 
	for(i=1;i<=N;i++)
	{
		scanf("%d",&C);
		n[i].f=-1;
		n[i].weight=C;
	}
	for(i=1;i<=P;i++) 
	{
		scanf("%d%d%d",&S,&E,&L);
		e[i].u=S;
		e[i].v=E;
		e[i].weight=L;
	}

	// 将每个定点的权重都分配到变上面去
	 for(i=1;i<=P;i++)
	 {
	 	e[i].weight=2*e[i].weight+n[e[i].u].weight+n[e[i].v].weight;
	 	//printf("%lf\n",e[i].weight);
	 }
	
	//KRUSKAL最小生成树算法
	MST_KRUSKAL(e,n,N,P);
	return 0;
}


void MST_KRUSKAL(struct edge* e,struct vectors* n,int N,int P)
{
	struct edge A[(N-1)+1];
	int i=1,j=1;
	int a=0;
	int b=0;
	//对边进行排序，由小到大
	kuaipai(e,1,P);
	//测试快排正确性
	//for(i=1;i<=P;i++)
	//{
	//	printf("%lf\n",e[i].weight);
	//}
	
	for(i=1;i<=P;i++)
	{
		if(root(e[i].u,n)!=root(e[i].v,n))
		{
			A[j].u=e[i].u;
			A[j].v=e[i].v;
			A[j].weight=e[i].weight;
			
			n[root(e[i].v,n)].f=root(e[i].u,n);
			
		//	printf("u %d v %d weight %lf\n",e[i].u,e[i].v,e[i].weight);
			a=a+A[j].weight;
			j=j+1;
		}
	}
	
	//
	b=n[1].weight;
	for(i=2;i<=N;i++)
	{
		if(b>n[i].weight)
		{
			b=n[i].weight;
		}
	}
	a=a+b;
	printf("%d",a);
	
	return;
}

int root(int flag,struct vectors* n)//返回u节点的根节点 
{
	int i=flag;
	while(n[i].f!=-1)
	{
		i=n[i].f;
	}
	return i;
}
/*
void kuaipai(struct edge* e,int l,int r)
{
	int i=l,j=r-1;
	int u=0,v=0;
	double weight=0;
	if(l>=r)
	{
		return;
	}
	
	for(i=l;i<=j;i++)
	{
		if(e[i].weight<=e[r].weight)
		{
			continue;
			
		}
		u=e[i].u;
		v=e[i].v;
		weight=e[i].weight;
		
		e[i].u=e[j].u;
		e[i].v=e[j].v;
		e[i].weight=e[j].weight;
		
		e[j].u=u;
		e[j].v=v;
		e[j].weight=weight;
		
		j=j-1;
	}
	i=j+1;
	u=e[i].u;
	v=e[i].v;
	weight=e[i].weight;
		
	e[i].u=e[r].u;
	e[i].v=e[r].v;
	e[i].weight=e[r].weight;
		
	e[r].u=u;
	e[r].v=v;
	e[r].weight=weight;
	
	
	kuaipai(e,1,i-1); 
	kuaipai(e,i+1,r); 
	return;
}*/
void kuaipai(struct edge* e,int l,int r)
{
	int i=l,j=l;
	int u=0,v=0;
	int weight=0;
	if(l>=r)
	{
		return;
	}
	
	for(i=l;i<=r-1;i++)
	{
		if(e[i].weight<=e[r].weight)
		{
			u=e[i].u;
			v=e[i].v;
			weight=e[i].weight;
		
			e[i].u=e[j].u;
			e[i].v=e[j].v;
			e[i].weight=e[j].weight;
		
			e[j].u=u;
			e[j].v=v;
			e[j].weight=weight;
		
			j=j+1;
			
		}
		
	}
	
	u=e[j].u;
	v=e[j].v;
	weight=e[j].weight;
		
	e[j].u=e[r].u;
	e[j].v=e[r].v;
	e[j].weight=e[r].weight;
		
	e[r].u=u;
	e[r].v=v;
	e[r].weight=weight;
	
	
	kuaipai(e,1,j-1); 
	kuaipai(e,j+1,r); 
	return;
}
