#include<stdio.h> 
#include<string.h> 
void A2a(char* s);
void count(int* A,char* s);
int main()
{
	char s1[88]={'\0'};
	char s2[88]={'\0'};
	int A[26+1]={0};
	int B[26+1]={0};
	int i=0;
	//输入数据 
	gets(s1);
	gets(s2);
	
	//字符串大写都变成小写
	A2a(s1);
	A2a(s2);
	
	//对每个单词的每个字母进行统计
	count(A,s1);
	count(B,s2);
	
	//比较A与B是否相同
	for(i=1;i<=26;i++)
	{
		if(A[i]!=B[i])
		{
			printf("N");
			return 0;
		}
	}
	printf("Y");
	return 0;
}

void A2a(char* s)
{
	int i=0;
	int l=strlen(s);
	for(i=0;i<l;i++)
	{
		if(s[i]>='A' && s[i]<='Z')
		{
			s[i]=s[i]+32;
		}
	}
	return;
}

void count(int* A,char* s)
{
	int i=0;
	int l=strlen(s);
	for(i=0;i<l;i++)
	{
		A[s[i]-'a'+1]++;
	}
	return;
}
