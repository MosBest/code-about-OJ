#include<stdio.h> 

void A(int n);
void ten2two(int n,int* a);
int main()
{
	int n=0;
	scanf("%d",&n);
	
	A(n);
	return 0;
}

void A(int n)
{
	int a[80]={0};
	int i=0;
	ten2two(n,a);
	
	for(i=1;i<=a[0];i++)
	{
		if(a[i]==1)
		{
			printf("2");
			if(i<a[0])
			{
				printf("+");
				continue;
			}
			else
			{
				break;
			}
		}
		
		printf("2");
		printf("(");
		A(a[i]);
		if(i==a[0] && a[i]==0)
		{
			printf("0)");
			break;
		}
		printf(")");
		
		if(i<a[0])
		{
			printf("+");
		}
		
	}
	
	return;
}

void ten2two(int n,int* a)
{
	int i=1,j=1;
	int shang=n;
	int yu=0;
	int b[81]={0};
	while(shang!=0)
	{
		yu=shang%2;
		shang=shang/2;
		b[i]=yu;
		i++;
	}
	i=i-1;
	b[0]=i;
	
	
	for(;i>=1;i--)
	{
		if(b[i]!=0)
		{
			a[j]=i-1;
			j++;
		}
	}
	a[0]=j-1;
	return;
}
