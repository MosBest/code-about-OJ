#include<stdio.h> 
#include<malloc.h>

void kuaipai(int* a,int l,int r);
int main()
{
	int m=0,n=0;
	int i=1,j=1;
	int* a=0;
	int b=0;
	int sum=0;
	scanf("%d",&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&n);
		a=(int*)malloc(sizeof(int)*(n+1));
		for(j=1;j<=n;j++)
		{
			scanf("%d",a+j);
		}
		kuaipai(a,1,n);
		sum=0;
		
		while(n>=0)
		{
			if(n==1)
			{
				printf("%d\n",sum+a[1]);
				break;
			}
			
			if(n==2)
			{
				printf("%d\n",sum+a[2]);
				break;
			}
			
			if(n==3)
			{
				printf("%d\n",sum+a[1]+a[2]+a[3]);
				break;
			}
			
			if(a[2]+a[2] < a[n-1]+a[1])
			{
				sum=sum+a[2]+a[1]+a[n]+a[2];
				n=n-2;
			}
			else
			{
				sum=sum+a[n]+a[1]+a[n-1]+a[1];
				n=n-2;
			}
			
		}
		
	}
	return 0;
}

void kuaipai(int* a,int l,int r)
{
	int i=l,j=l;
	int x=a[r];
	int y=0;
	if(l>=r)
		return;
	
	for(i=l;i<=r-1;i++)
	{
		if(a[i]<x)
		{
			y=a[i];
			a[i]=a[j];
			a[j]=y;
			j++;
		}
	}
	y=a[j];
	a[j]=a[r];
	a[r]=y;
	
	kuaipai(a,l,j-1);
	kuaipai(a,j+1,r);
}
