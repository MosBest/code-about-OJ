#include<stdio.h> 
#include<malloc.h>
void kuaipai(int* a,int l,int r);
int main()
{
	int s=0;
	int w=0,n=0;
	int i=0,j=0,k=0;
	int num=0;
	int* a=0;
	scanf("%d",&s);
	for(i=1;i<=s;i++)
	{
		scanf("%d%d",&w,&n);
		a=(int*)malloc(sizeof(int)*(n+1)); 
		for(j=1;j<=n;j++)
		{
			scanf("%d",a+j);
		}
		kuaipai(a,1,n);
		j=1;
		k=n;
		num=0;
		while(j<k)
		{
			if(a[j]+a[k]<=w)
			{
				num++;
				j++;
				k--;
			}
			else
			{
				num++;
				k--;
			}
		}
		
		if(j==k)
		{
			num++;
		}
		printf("%d\n",num);
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
			y=a[j];
			a[j]=a[i];
			a[i]=y;
			j++;
		}
	}
	
	y=a[j];
	a[j]=a[r];
	a[r]=y;
	
	kuaipai(a,l,j-1);
	kuaipai(a,j+1,r);
	return;
}
