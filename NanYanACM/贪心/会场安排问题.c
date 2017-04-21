#include<stdio.h> 
#include<malloc.h>
struct data{
	int B;
	int E;
};

void kuaipai(struct data* a, int l,int r);
//必须写成struct data* a 不能够写成struct data * a 

int main()
{
	int m=0,n=0;
	int i=1,j=1;
	int B=0,E=0;
	int num=0;
	int k=0;
	struct data* a=0;
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&n);
		a=(struct data*)malloc(sizeof(struct data)*(n+1));
		num=0;
		for(j=1;j<=n;j++)
		{
			scanf("%d%d",&B,&E);
			a[j].B=B;
			a[j].E=E;
		}
		
		kuaipai(a,1,n);//快排，按照a[i].E的大小从小到大排序 
		num=1;
		k=a[1].E;
		for(j=2;j<=n;j++)
		{
			if(a[j].B>k)
			{
				k=a[j].E;
				num++;
			}
		}
		printf("%d\n",num);
		free(a);
	}
	return 0;
}

void kuaipai(struct data* a, int l,int r) 
{
	int i=l,j=l;
	int k=a[r].E;
	int x=0,y=0;
	if(l>=r)
		return;
	
	for(i=l;i<=r-1;i++)
	{
		if(a[i].E<k)
		{
			x=a[i].B;
			y=a[i].E;
			
			a[i].B=a[j].B;
			a[i].E=a[j].E;
			
			a[j].B=x;
			a[j].E=y;
			
			j++;
		}
	}
	x=a[r].B;
	y=a[r].E;
			
	a[r].B=a[j].B;
	a[r].E=a[j].E;
			
	a[j].B=x;
	a[j].E=y;
	
	kuaipai(a,l,j-1);
	kuaipai(a,j+1,r);
	return;
}
