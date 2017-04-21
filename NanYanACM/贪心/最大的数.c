#include<stdio.h> 

int main()
{
	
	int n=0;
	int i=0,j=1;
	int sum=1;
	int a[10000+1];
	int b[10000+1];
	

	while(scanf("%d",&n)!=EOF)
	{
		
		for(i=1;i<=n;i++)
		{
			scanf("%d",a+i);
		}
		sum=1;
		for(i=1,j=1;i<=n;i++)
		{
			if(a[i]!=1)
			{
				b[j]=a[i];
				j++;
			}
			else
			{
				if(i==1)
				{
					if(n==1)
					{
						b[j]=a[i];
						j++;
						break;
					}
					b[j]=a[i]+a[i+1];
					i++;
					j++;
					continue;
				}
				
				if(i==n || b[j-1]<=a[i+1])
				{
					
					b[j-1]=b[j-1]+a[i];
					
				}
				else
				{
					if(b[j-1]==2)
					{
						b[j-1]=b[j-1]+a[i];
					
					}
					else
					{
						b[j]=a[i]+a[i+1];
						i++;
						j++;
					}
					
				}
			}
		}
		j=j-1; 
		for(i=1;i<=j;i++)
		{
			sum=(sum*b[i])%10086;
		}
		printf("%d\n",sum);
	}
	
	return 0;
	
}
