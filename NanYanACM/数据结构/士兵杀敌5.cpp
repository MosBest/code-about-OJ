#include<iostream>
#include<cstdio>

int N,C,Q;
int b[1000000+1];
int bi[1000000+1];
void questy(int* a,int i,int data)
{
	
	while(i<=N)
	{
		a[i]+=data;
		i+=(i&(-i));
	}
}


int SUM(int* a,int i)
{
	int sum=0;
	while(i>0)
	{
		sum+=a[i];
		i-=(i&(-i));
	}
	
	return sum;
}


int main()
{
	scanf("%d%d%d",&N,&C,&Q);
	int mi,ni,ai;
	for(int i=1;i<=C;i++)
	{
		
		scanf("%d%d%d",&mi,&ni,&ai);
		
		questy(b,mi,ai);
		questy(b,ni+1,-ai);
		
		questy(bi,mi,mi*ai);
		questy(bi,ni+1,-1*(ni+1)*ai);
	}
	
	int sum_a , sum_b; 
	for(int i=1;i<=Q;i++)
	{
		scanf("%d%d",&mi,&ni);
		//segma(org[i]) + (x+1)*segma(delta[i]) -segma(delta[i]*i)，1 <= i <= x  
		//因为A为空，所以orj[i] ==0 
		sum_a=0+(ni+1)*SUM(b,ni)-SUM(bi,ni);
		sum_b=0+mi*SUM(b,mi-1)-SUM(bi,mi-1);
		printf("%d\n",sum_a-sum_b);
		
	}
	return 0;
}
