#include <stdio.h> 
#include<malloc.h>
#include<string.h>

int main(void)
{
	char* s="Trap a rat! Starepiper
at Star apart."; 
	int i=0;
	char* q;
	int l=strlen(s);   
	printf("l����%d\n",l);
	q=(char*)malloc(l*sizeof(char));//��Ҫ����1

	if(*s=='\0') 
	{
		*q='\0';
		printf("����Ϊ0");
	}
	
	else
	for(i=0;i<strlen(s);i++)//���ڳ���Ϊ0 �������ֱ������ȥ�� 
	{
		q[i]=s[strlen(s)-i-1];
		printf("%d",i);
	}
	q[i+2]='\0'; // �������һ���ַ�Ҫ�趨Ϊ0 
	
	printf("\n q����%d\n",strlen(q));
	printf("%s",q);

	free(q);
	return 0;
}


/**************************************************************
Ҫ�󣺽��ַ�������
���룺��hello��
�������olleh��
****************************************************************/

/************************************************************** 
˼�룺
����һ�����鵹�Ŵ������Ϳ�����
***************************************************************/ 

/*************************************************************
���룺
char* reverseString(char* s) {
    int i=0;
	char* q=NULL;
	int l=strlen(s);
	q=(char* )malloc((l+1)*sizeof(char));
	if(*s=='\0')
	{
	    *q='\0';
	}
	else
	{
	for(i=0;i<l;i++)
	{
		q[i]=s[l-i-1];
	}
	}
	q[i]='\0';
	return q;
}
***********************************************************/

/*************************************************************
����/���⣺
1. leetcode�Դ��Ĵ���༭����һ��׼ȷ
2. ������Ϊ�����������ַ�����ʱ�����
����q=(char* )malloc(0*sizeof(char))Ҳ�����ռ��q
������Ϊ����ʱ��strlen(s)Ϊ0��������ִ��forѭ����䣬��q�Ѿ��������˿ռ䣬��ΪNULL����ô�����ֵΪ�������ݣ�������һ������
3. ������qָ��8���ֽڵĳ���ʱ���������strlen(q)�ͱ����11��������8
ԭ����c�����У���������char��ʾ �ַ�����ʱ��һ��Ҫ�Լ���ĩβ���ϡ�\0��,Ҫ��Ȼ���༭���ͻ᲻�ϵı��� ���飬ֱ���ҵ���һ��'\0'����Ϊ���յ��ַ������ǵ�һ���ַ������'\0',�������'\0'���Ѿ�Խ���ˡ�

4. ����Ŀռ�Ӧ���� strlen(s)+1��������strlen(s)����ΪҪ��������һ��'\0'.
******************************************************************/
