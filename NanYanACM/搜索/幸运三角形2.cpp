#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
	int n=0;
	while(scanf("%d",&n)!=EOF)
	{
		int a[n];
		//0表示'-' , 1表示'+' 
		int num=0;
		int i;
		int k=0;//k记录1的个数 
		if((n+1)*n/2%2==1)
		{
			printf("%d\n",0);
			continue;
		}
			
		int q=pow(2,n);
		for(a[0]=0;a[0]<q;a[0]++) 
		{
			k=0;
			for(i=0;i<n;i++)
			{
				k+=0x01 & (a[0]>>i);
			}
			
			for(i=1;i<=n-1;i++) 
			{
				a[i]=a[i-1]^(a[i-1]>>1);
				
				for(int j=0;j<n-i;j++)
				{
					k+=0x01 & (a[i]>>j);
				}
				
				if(k>(n+1)*n/4)
						break;
			}
			if(i>=n && k==(n+1)*n/4)
				{
					num++;
				}
		}
		printf("%d\n",num);
	}
	return 0;
}
