#include<stdio.h>
#include<malloc.h>

void kauipai(int* a,int l,int n);

int main()
{
	int T=0;
	int n=0;
	int i=0,j=0;
	int* a=0;
	int* b=0;
	int result=0;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d",&n);
		a=(int*)malloc(sizeof(int)*(n+1));
		b=(int*)malloc(sizeof(int)*(n+1));
		
		for(j=1;j<=n;j++)
		{
			scanf("%d",a+j);
		}
		
		for(j=1;j<=n;j++)
		{
			scanf("%d",b+j);
		}
		kuaipai(a,1,n);
		kuaipai(b,1,n);
		
		result=0;
		for(j=1;j<=n;j++)
		{
			result=result+a[j]*b[n-j+1]; //用数组a的最大值，去乘以数组b的最小值 。得到的就是最小值 
		}
		printf("%d\n",result);
	}
	return 0;
}

void kuaipai(int* a,int l,int r)
{
	int i=l,j=l;
	int b=0;
	if(l>=r)
	{
		return;
	}
	for(i=l;i<=r-1;i++)
	{
		if(a[i]<a[r]) 
		{
			b=a[j];
			a[j]=a[i];
			a[i]=b;
			j++;
		}
	}
	
	b=a[r];
	a[r]=a[j];
	a[j]=b;
	
	kuaipai(a,l,j-1);
	kuaipai(a,j+1,r);
	
	return;
}

