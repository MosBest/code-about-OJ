#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int N,C,M;
bool notIn(int k,int* m)
{
	for(int i=0;i<M;i++)
	{
		if( (k>='0' && k<='9' && k==m[i]+'0') || (k>='A' && k<='F' && k==m[i]-10+'A'))
			return false;
	}
	return true;
}

void ten2C(int A,int C,char* B,int* m)
{
	int i;
	int a; 
	for(i=0;i<=499 && A!=0;i++)
	{
		printf("%d ",i);
		
		a=A%C;
		if(a>=0 && a<=9)
			B[i]=a+'0';
		else
			B[i]=a+'A'-10;
		
		if(notIn(B[i], m))
		{
			B[501]='#';
			return;
		}
		A=A/C;
	}
	if(A!=0)
	{
		B[501]='&';
		return;
	}
	B[i]='\0';
	return;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int dl=1;dl<=T;dl++)
	{
		scanf("%d%d%d",&N,&C,&M);
		int m[M];
		for(int i=0;i<M;i++)
			scanf("%d",m+i);
		int i=1;
		while(true)
		{
			int A=N*i;
			char B[502];
			B[501]='\0';
			ten2C(A,C,B,m);
			if(B[501]=='#')
			{
				i++;
				continue;
			}
			
			if(B[501]=='&')
			{
				printf("So Sorry.\n");
				break;
			}
			int j;
			for(j=strlen(B)-1;j>=0;j--)
			{
				if(B[j]!='0')
					break;
			}
			for(j;j>=0;j--)
			{
				printf("%c",B[j]);
			}
			printf("\n");
			break;
		}
	}
	return 0;
}
