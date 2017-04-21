#include<iostream>
#include<cstdio>
#include<cstring> 
#define mod 1000007
using namespace std;

typedef struct{
	long long int k[3][3];
}node;

node Multiply(node f , node A)
{
	node c;	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			c.k[i][j]=0;
			for(int k=0;k<3;k++)
			{
				c.k[i][j]+=f.k[i][k]*A.k[k][j];
				c.k[i][j]%=1000007;
			}
		}
	}
	return c;
}

node Matrix_fast_power(int a,int b,int c,int n)
{
	node mi;
	memset(mi.k,0,sizeof(mi.k));
	mi.k[0][0]=b;
	mi.k[0][1]=a;
	mi.k[0][2]=c;
	mi.k[1][0]=mi.k[2][2]=1;
	
	node f;
	memset(f.k,0,sizeof(f.k));
	f.k[0][0]=f.k[1][1]=f.k[2][2]=1;

	while(n)
	{
		if(n&1)
		{
			f=Multiply(f,mi);
		}
		mi=Multiply(mi,mi);
		n=n>>1;
	}
	return f;	
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		long long int d,e,a,b,c,n;
		scanf("%lld%lld%lld%lld%lld%lld",&d,&e,&a,&b,&c,&n);
		node mi;
		
		if(n == 1)
			printf("%lld\n",(d+mod)%mod);
		 if(n == 2)
				printf("%lld\n",(e+mod)%mod);
		else
		{
		
		mi=Matrix_fast_power(a,b,c,n-2);
		node r;		
		memset(r.k,0,sizeof(r.k));
		
		r.k[0][0]=e;
		r.k[1][0]=d;
		r.k[2][0]=1;
		r=Multiply(mi,r);
		
		printf("%lld\n",(r.k[0][0]+mod)%mod);
		}
	}
	return 0;
}
