//һֱ�����⣬�����ŷ��֣���Ȼ��+- �� & �����ȼ�Ū���ˡ� 
#include<iostream> 
#include<stdio.h>
#include<string.h>

using namespace std;
int a[1001001];
int c[1001000];
int N,M;

int lowbit(int i)
{
   return -i & i;
}
//�����1��i�ĺ� 
int sum(int i)
{
	int k=0;
	for(;i>0;)
	{
		k+=c[i];
		int m=i&(-i);
		i=i-m;	
	}
	return k;
}

//����a[]��Ԫ��ʱ 
void ADD(int i,int num)
{
	//a[i]+=num; a[]���� ���ڽ���c[]���������ĸ��ģ����Ҷ���a[]�޹��� 

	while(i<=N)
	{
		c[i]+=num;
		i=i+(i&(-i));
		
	}
}

int main()
{

	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",a+i);
		
	}
	a[0]=0;
	/*
	int x;
	for(int i=1;i<=N;i++){
        scanf("%d",&x);
        ADD(i,x);
    }*/
	//������״����c[]
	
	for(int i=1;i<=N;i++)
	{
		int m=i&(-i);
		c[i]=0;
		for(int j=0;j<m;j++)
			c[i]+=a[i-j];
	}
	//���ʻ��߸������� 
	int m,n;
	char s[10];
	for(int i=0;i<M;i++)
	{
		scanf("%s %d %d",s,&m,&n);
		if(strcmp(s, "QUERY") == 0)
		{
			printf("%d\n",sum(n)-sum(m-1));
		}
		else
		{
			ADD(m,n);
			
		}
	}
	
	return 0;
}
