#include<stdio.h> 
#include<malloc.h>
#include<string.h>

struct node{
	int num;
	int len;
};
int main()
{
	int i=0,j=0,k=0,l=0;
	int L=0;
	int len=0;
	char s[100]={'\0'};
	scanf("%d",&L);
	getchar();
	gets(s);
	len=strlen(s);
	struct node a[len];//��Σ��±�0Ҳ�� 
	for(i=L;i<=len;i++)//i��ʾ�Ӵ��ĳ��� 
	{
		for(j=0;j<len-1-i;j++)
		{
			for(k=j+1;k<=len-1-i;k++) 
			{
				for(l=0;l<=i;l++) 
				{
					if(s[j+l]!=s[k+l])
					{
						break;
					}
				}
				
				if(l>i)//����ƥ���� 
				{
					
				}
			}
		}
	}
	return 0;
}
