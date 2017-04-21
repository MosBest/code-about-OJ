#include<stdio.h>

int jiecheng(int* a ,int m);
int main()
{
	int m=0,n=0;
	int i=0,j=0;
	scanf("%d",&m);
	int k=0,l=0;
	int a[100]={1}; //a[i] 表示前i个数的阶乘 
	l=jiecheng(a,1000000);//计算k，使得k!<1000000<(k+1)!
	for(i=1;i<=m;i++)
	{
		scanf("%d",&n);
		//n=i;
		k=l;
		while(n>0 && k>0)
		{
			for(j=1;j<=k;j++)
			{
				if(a[j]<=n && (a[j+1]>n || j==k))
				{
					n=n-a[j];
					//printf("%d ",j);
					k=j-1;
					break;
				}
			}
		}
		//printf("%d ",i);
		if(n>0)
		{
			printf("No\n");
			
		}
		else
		{
			printf("Yes\n");
		}
		
	}
	return 0;
}

int jiecheng(int* a , int m)
{
	int i=1;
	a[1]=1;
	for(i=2;;i++)
	{
		if(a[i-1]>m)
		{
			break;
		}
		a[i]=a[i-1]*i;
		
	}
	return i-1; 
}
