#include<stdio.h> 
#include<math.h>
long long int sushu(int n);
int notsushu(long long int num);
long long int createPrimes( const long long int a,int n);
int main()
{
	int n=0;
	long long int a=0;
	scanf("%d",&n);
	a=sushu(n);//输出第n个素数对应的值a 
	//printf("a:%I64d",a);
	
	printf("%I64d",createPrimes(a,n));
	
	return 0;
}

long long int sushu(int n)
{
	int i=0;
	long long int num=0;
	num=2;
	for(i=0;i<n;i++)
	{
		
		while(notsushu(num))
		{
			num++;
		}
		num++;
	}
	return num-1;
}

int notsushu(long long int num)
{
	int i=2;
	for(i=2;i<=sqrt(num);i++)
	{
		if(num%i==0)
		{
			return 1;
		}
		
	}
	return 0;
}

long long int  createPrimes(const long long int a , int n)
{
	int shu[a+1];
	int i=0;
	int j=0;
	int b=0;
	long long int result=1;
	for(i=0;i<=a;i++)
	{
		shu[i]=0;
	}
	for(i=2;i<=a;i++)
	{
		if(shu[i]==0)
		{
			for(b=i*2;b<=a;b=b+i)
			{
				shu[b]=1;
			}
		}
	}
	
	for(i=2;i<=a;i++)
	{
		if(shu[i]==0)
		{
			result=(result%50000)*i;
		}
	}
	
	return result%50000;
}
