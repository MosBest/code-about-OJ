#include<stdio.h> 
#include<string.h>

int findK(char* s,int i,int K);
void change(char* s,int i,int h);
int main()
{
	char s[30]={'\0'};
	int K=0;
	int n=0;
	int i=0;
	int h=0,x=0;
	while(scanf("%s",s)!=EOF)//scanf(%s)不能存放空格，认为空格就是回车键 ,二gets()将空格视为一个普通字符 
	{
		scanf("%d",&K);
		n=strlen(s);
		
		for(i=0;i<n && K>0;i++) 
		{
			if(K>=n-i)
			{
				h=findK(s,i,n-i);
			}
			else
			{
				h=findK(s,i,K);
			}
			
			if(s[h]>s[i])
			{
				x=s[h];
				change(s,i,h);
				s[i]=x;
				K=K-(h-i);
			}
		}
		
		printf("%s\n",s);
	}
	return 0;
}

int findK(char* s,int i,int K)
{
	int j=i+1;
	int b=j;
	for(j=i+2;j<=i+K;j++)
	{
		if(s[b]<s[j])
		{
			b=j;
		}
	}
	return b;
}
void change(char* s,int i,int h)
{
	int j=0;
	for(j=h;j>=i+1;j--)
	{
		s[j]=s[j-1];
	}
	return;
}
