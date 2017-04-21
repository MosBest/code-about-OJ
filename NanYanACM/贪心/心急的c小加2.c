#include<stdio.h>
#include<malloc.h>

struct data{
	int l;
	int w;
	int flag;  //0表示未被访问,1表示已经访问
};

void kuaipai(struct data* a,int l,int r);
int smallest(struct data* a,int l,int r);
void kuaipai2(int* a,int l,int r);
int main()
{
	int T=0,N=0;
	int i=0,j=0,k=0,s=0;
	int L=0,W=0;
	int num=0;
	int b=1,c=1;
	int* r=0;
	struct data* a=0;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
	{
		scanf("%d",&N);
		a=(struct data*)malloc(sizeof(struct data)*(N+1));
		r=(int*)malloc(sizeof(int)*(N+1));
		for(j=1;j<=N;j++)
		{
			scanf("%d%d",&a[j].l,&a[j].w);
			a[j].flag=0;
		}
		kuaipai(a,1,N);//按照a[i].l从大到小排序 
		
		//for(j=1;j<=N;j++)
	//	{
	//		printf("%d  %d  %d\n",a[j].l,a[j].w,a[j].flag);
	//	}
		b=1;
		r[b]=a[b].w;
		r[0]=1;
		c=2;
		for(j=2;j<=N;j++)
		{
			if(a[j].l==a[b].l)
			{
				r[c]=a[j].w;
				c++;
				r[0]++;
				if(j!=N)
				{
					continue;
				}
				
			}
			kuaipai2(r,1,r[0]);
			
			for(c=1;c<=r[0];c++)
			{
				a[b+c-1].w=r[c];
			//	printf("%d\n",a[b+c-1].w);
			}
			b=j;
			c=1;
			r[c]=a[b].w;
			c++;
			r[0]=1;
		}
		
		//for(j=1;j<=N;j++)
		//{
		//	printf("%d  %d  %d\n",a[j].l,a[j].w,a[j].flag);
	//	}
		a[0].flag=N;
		num=1;
		while(1)
		{
			for(k=1;k<=N;k++)
			{
				if(a[k].flag==0)
				{
					a[k].flag=1;
				//	printf("%d  %d  %d\n",a[k].l,a[k].w,a[k].flag);
					num++;
					break;
				}
			}
			
			if(k>=N)
			{
				break;
			}
			
			
			s=k;
			for(k=k+1;k<=N;k++)
			{
				if(a[k].flag==0 && a[k].w>=a[s].w) 
				{
					a[k].flag=1;
			//		printf("%d  %d  %d\n",a[k].l,a[k].w,a[k].flag);
					s=k;
				}
			}
			
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

void kuaipai2(int* a,int l,int r)
{
	int i=l,j=l;
	int k=a[r];
	int y=0;
	if(l>=r)
		return;
	
	for(i=l;i<=r-1;i++)
	{
		if(a[i]<k)
		{
			
			y=a[i];
			
		
			a[i]=a[j];
			
		
			a[j]=y;
			
			j++;
		}
	}
	
	
	y=a[r];
	

	a[r]=a[j];
	
	
	a[j]=y;
	
	kuaipai2(a,l,j-1);
	kuaipai2(a,j+1,r);
	
	return;
}
