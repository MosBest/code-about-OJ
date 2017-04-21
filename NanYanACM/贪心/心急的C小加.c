#include<stdio.h>
#include<malloc.h>

struct data{
	int l;
	int w;
	int flag;  //0表示未被访问,1表示已经访问
};

void kuaipai(struct data* a,int l,int r);
int smallest(struct data* a,int l,int r);
int main()
{
	int T=0,N=0;
	int i=0,j=0;
	int L=0,W=0;
	int num=0;
	int b=1,r=0;
	struct data* a=0;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d",&N);
		a=(struct data*)malloc(sizeof(struct data)*(N+1));
		for(j=1;j<=N;j++)
		{
			scanf("%d%d",&a[j].l,&a[j].w);
			a[j].flag=0;
		}
		kuaipai(a,1,N);//按照a[i].l从大到小排序 
		
		a[0].flag=N;
		num=1;
		while(a[0].flag>0)
		{
			for(j=1;j<=N;j++)
			{
				if(a[j].flag==0)
				{
					b=j;
					break;
				}
			}
			
			for(;b<=N;)
			{
				b=smallest(a,b,N);
				//printf("%d ",b);
				if(a[b].flag==1)
				{
					break;
				}
				a[b].flag=1;
				b=b+1;
				a[0].flag--;
			}
			
			for(j=N;j>=b;j--)
			{
				if(a[j].flag==0)
				{
					N=j;
					break;
				}
			}
			num++;
		}
		printf("%d\n",num-1);
	}
	
	return 0;
}

void kuaipai(struct data* a,int l,int r)
{
	int i=l,j=l;
	int k=a[r].l;
	int x=0,y=0;
	if(l>=r)
		return;
	
	for(i=l;i<=r-1;i++)
	{
		if(a[i].l<k)
		{
			x=a[i].l;
			y=a[i].w;
			
			a[i].l=a[j].l;
			a[i].w=a[j].w;
			
			a[j].l=x;
			a[j].w=y;
			
			j++;
		}
	}
	
	x=a[r].l;
	y=a[r].w;
	
	a[r].l=a[j].l;
	a[r].w=a[j].w;
	
	a[j].l=x;
	a[j].w=y;
	
	kuaipai(a,l,j-1);
	kuaipai(a,j+1,r);
	
	return;
}

int smallest(struct data* a,int l,int r)
{
	int j=l;
	int b=l;
	
	for(j=l;j<=r;j++)
	{
		if(a[j].flag==0)
		{
			b=j;
			break;
		}
	}
	
	for(j=b;j<=r;j++)
	{
		if(a[j].flag==0 && a[b].w>a[j].w)
		{
			b=j;//表示第j个a的w是最小的 ,b表示的是对应的下标 
		}
	}
	return b;
}
