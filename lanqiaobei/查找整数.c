#include<stdio.h>

int main()
{
	int n=0;
	int b[1000]={0};
	int a=0;
	int i=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",b+i);
	}
	scanf("%d",&a);
	
	for(i=0;i<n && b[i]!=a ;i++)
		;
	
	if(i>=n)	
	{
		printf("%d",-1);
	}
	else
	{
		printf("%d",i+1);
	}

	return 0;
}
