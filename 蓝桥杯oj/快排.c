#include<stdio.h>

void kuaipai(int *a,int l,int right);

int main()
{
	int n=0;
	int a[200]={0};
	int i=0;
	scanf("%d",&n);
	for(i=1;i<n+1;i++)
	{
		scanf("%d",a+i);
	}
	
	kuaipai(a,1,n);
	for(i=1;i<n+1;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}

void kuaipai(int *a,int l,int right)
{
	int i=l;
	int j=l;
	int x=a[right];
	int A=-1;
	
	if(l>=right)
	return;
	while(i<right)
	{
		if(a[i]<x)
		{
			A=a[j];
			a[j]=a[i];
			a[i]=A;
			j++;
		}
		i++;
	}
	a[right]=a[j];
	a[j]=x;
	
	kuaipai(a,l,j-1);
	kuaipai(a,j+1,right);
	
	
}
