#include<iostream> 
#include<cstdio>
#include<cmath>

//有半天卡在了优先级上面了 
using namespace std;

// const int NN =(int)(log(100100)/log(2));
int a[100100];
int MAX[100100][ 22+1];
int MIN[100010][22 +1];
int N,Q;
int main()
{
	scanf("%d%d",&N,&Q);
	
	for(int i=1;i<=N;i++)
		scanf("%d",a+i);
		
	//st算法 动态规划 初始化 max min
	for(int i=1;i<=N;i++)
	{
		MAX[i][0]=a[i];
		MIN[i][0]=a[i];
	}
	
	for( int j=1;j<=(log(N)/log(2));j++)
	{
		for(int i=1;i<=N-pow(2,j)+1;i++)
		{
			MAX[i][j]=max(MAX[i][j-1],MAX[i+(int)pow(2,j-1)][j-1]);
			MIN[i][j]=min(MIN[i][j-1],MIN[i+(int)pow(2,j-1)][j-1]);
		}
	}
	
	int m,n,k,e,f;
	for(int i=0;i<Q;i++)
	{
		scanf("%d%d",&m,&n);
		k=(int)(log(n-m+1)/log(2));
		e=max(MAX[m][k],MAX[n-(int)pow(2,k)+1][k]);
		f=min(MIN[m][k],MIN[n-(int)pow(2,k)+1][k]);
		printf("%d\n",e-f);
	}
	
	return 0;
}
