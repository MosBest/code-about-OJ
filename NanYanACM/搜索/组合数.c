#include<stdio.h> 

int main()
{
	int n=0,r=0;
	int i=0,j=0;
	scanf("%d%d",&n,&r);
	int a[r+1];
	for(i=1;i<=r;i++)
	{
		a[i]=n-r+i;
	}
	while(a[r]>r)
	{
		for(i=1;i<=r && a[r]!=r;i++)
		{
			if(a[i]==i-1)
			{
				a[i+1]--;
				j=i;
				while(j>=1)
				{
					a[j]=a[j+1]-1;
					j--;
				}
			}
		}
		
		for(j=r;j>=1;j--)
		{
			printf("%d",a[j]);
		}
		printf("\n");
		a[1]--;
	}
	
	return 0;
}
