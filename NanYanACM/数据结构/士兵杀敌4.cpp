#include<iostream> 
#include<cstdio>

using namespace std;
int C[1000000+1];
int T,M;
void ADD(int i,int data)
{
	while(i>0)
	{
		C[i]+=data;
		i-=(i&(-i));
	}
}

int questy(int i) 
{
	int sum=0;
	while(i<=M)
	{
		sum+=C[i];
		i+=(i&(-i));
	}
	
	return sum;
}

int main()
{
	
	scanf("%d%d",&T,&M);
	char s[10];
	int m[3+1];
	for(int i=1;i<=T;i++)
	{
		scanf("%s",s);
		if(s[0]=='A')
		{
			for(int j=1;j<=3;j++)
			{
				scanf("%d",m+j);
			}
			ADD(m[2],m[3]);
			ADD(m[1]-1,-m[3]);
			
		}
		else
		{
			scanf("%d",m+1);
			printf("%d\n",questy(m[1]));
		}
	}
	
	return 0;
}
