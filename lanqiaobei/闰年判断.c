//�����ж�
//��4�ı���������100�ı�����������400�ı��� 

#include<stdio.h>

int main()
{
	int n=0;
	scanf("%d",&n);
	if((n%4==0 && n%100!=0) || n%400==0)
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
	return 0;
}
