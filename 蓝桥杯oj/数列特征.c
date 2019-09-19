#include<stdio.h>

int main()
{
	int max=0;
	int min=0;
	int sum=0;
	int n=0;
	int i=0;
	int a[10000]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	
	min=max=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
		else if(a[i]<min)
		{
			min=a[i];
		}
		
		sum+=a[i];
	}
	
	printf("%d\n%d\n%d",max,min,sum);
	
	return 0;
}
