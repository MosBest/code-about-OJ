#include<stdio.h>
#include<malloc.h> 

int maopao(int* a,int n,int K);

int main()
{
	int n=0;
	int* a=0;
	int* b=0;
	int m=0;
	int l=0,r=0,K=0;
	int i=0;
	int j=0;
	int q[1000]={0};
	scanf("%d",&n);
	a=(int*)malloc(sizeof(int)*(n+1));
	for(i=1;i<n+1;i++)
	{
		scanf("%d",a+i);
	}
	scanf("%d",&m);
	
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&l,&r,&K);
		b=(int*)malloc(sizeof(int)*(r-l+1+1));
		for(j=l;j<=r;j++)
		{
			b[j-l+1]=a[j];
		}
		
		q[i]=maopao(b,r-l+1,K);
	}
	
	for(i=1;i<=m;i++)
	{
		printf("%d\n",q[i]);
	}
	
	
	return 0;
}

int maopao(int* a,int n,int K)
{
	int i=0,j=0;
	int x=0;
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			if(a[j]<a[j+1])
			{
				x=a[j];
				a[j]=a[j+1];
				a[j+1]=x;
			}
		}
	}
	
	return a[K];
}
