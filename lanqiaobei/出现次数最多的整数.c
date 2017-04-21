#include<stdio.h> 

int main()
{
	int c=0,k=0;
	int i=0,j=0;
	int N=0;
	scanf("%d",&N);
	if(N<=0) 
	{
		return 0; 
	} 
	
	int a[N+1];
	int b[N+1];
	
	for(i=1;i<=N;i++)
	{
		scanf("%d",a+i);
		b[i]=0;
	}
	
	
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N-i;j++)
		{
			if(a[i]!=a[i+j])
			{
				break;
			}
		}
		b[i]=j;
		if(b[i]>c)
		{
			c=b[i];
			k=a[i];
		}
		i=i+j-1;
		
	}
	
	printf("%d",k);
	return 0;
}
