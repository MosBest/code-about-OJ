#include<stdio.h>

struct data{
	int a;//左闭区间 
	int b;//右闭区间
};
void kuaipai(struct data* node,int l,int r);
int main()
{
	int m=0,n=0;
	int i=0;
	struct data node[100+1];
	int num=1;
	int N=0;
	
	while(scanf("%d",&N)!=EOF)
	{
		for(i=1;i<=N;i++)
		{
			scanf("%d%d",&node[i].a,&node[i].b);
		}
		
		kuaipai(node,1,N);//按照b从小到大排序 
		num=1;
		m=node[1].a;
		n=node[1].b;
		
		for(i=2;i<=N;i++) 
		{
			if(node[i].a<=m)
				continue;
			if(node[i].a>m && node[i].a<=n)
			{
				m=node[i].a;
				continue;
			}
			
			if(node[i].a > n)
			{
				num++;
				m=node[i].a;
				n=node[i].b;
			}
		}
		
		printf("%d\n",num);
	}
	return 0;
}

void kuaipai(struct data* node,int l,int r)
{
	int i=l,j=l;
	int x=0,y=0;
	int k=node[r].b;
	
	if(l>=r)
		return;
	for(i=l;i<=r-1;i++)
	{
		if(node[i].b<k)
		{
			x=node[i].a;
			y=node[i].b;
			
			node[i].a=node[j].a;
			node[i].b=node[j].b;
			
			node[j].a=x;
			node[j].b=y;
			j++;
		}
	}
	
	x=node[r].a;
	y=node[r].b;
	
	node[r].a=node[j].a;
	node[r].b=node[j].b;
	
	node[j].a=x;
	node[j].b=y;
	
	kuaipai(node,l,j-1);
	kuaipai(node,j+1,r);
	return;
}
