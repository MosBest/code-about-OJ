/*
//����һ�����õݹ飬���ǵ����㵽n=30ʱ���Ͳ����ˣ�����˵n=1000000��
//���ԣ��ݹ���oj��ò��� 
#include<stdio.h>
int main()
{
	int n=0; 
	scanf("%d",&n);
	printf("%d",Fibonacci(n));	
	return 0;
}
int Fibonacci(int n)
{
	if(n<=2)
	return 1;
	
	return  Fibonacci(n-1)%10007+ Fibonacci(n-2)%10007;
}*/

//���������ǵݹ� ʽ��Fibonacci ����
//����(a%c+b%c)%c=(a+b)%c
//����F(n)=F(n-1)+F(n-2),���������ʽ�洢F(n),��forѭ����һ�������㣬�ȵݹ�Ҫ��ö� 
#include <stdio.h>
#include <malloc.h>
int main()
{
	int n=0;
	int i=0;
	int* a=0;
	scanf("%d",&n);
	a=(int*)malloc(sizeof(int)*(n+1));
	a[1]=1;
	a[2]=1;
	for(i=3;i<=n;i++)
	{
		a[i]=(a[i-1]+a[i-2])%10007;//���� a[i]=(a[i-1]%10007+a[i-2]%10007)%10007
	}
	printf("%d",a[n]);
	return 0;
}

//����������
//����һ �������õݹ鷽ʽ�ύ���ʱ���ɼ�Ϊ30% 
//��������ǵݹ��ύ�����Ϊ60%
//����ԭ��forѭ����д���� a[i]=a[i-1]%10007+a[i-2]%10007; ��������ȷ����ʵ
//�����⡣����������룬��a[1~n] ���е����ݴ�ӡ����������n<=23ʱ��û�����⣬��Ϊ
//a[22],a[11] �� Fibonacci���к�С��10007������a[22]%10007+a[21]%10007 ���� (a[22]+a[21])%10007
//���ǵ�����n==24 ʱ��a[22]<10007,a[23]<10007,�� a[22]%10007+a[23]%10007=a[22]+a[23]>10007������
//����������ʽӦ��дΪ a[i]=(a[i-1]%10007+a[i-2]%10007)%10007;���� a[i]=(a[i-1]+a[i-2])%10007;
/*
#include <stdio.h>
#include <malloc.h>
int main()
{
	int n=0;
	int i=0;
	int* a=0;
	scanf("%d",&n);
	a=(int*)malloc(sizeof(int)*(n+1));
	a[1]=1;
	a[2]=1;
	for(i=3;i<=n;i++)
	{
		a[i]=(a[i-1]+a[i-2])%10007;
		printf("a[%d] : %d  ",i,a[i]);
	}
	printf("\n a[n] %d\n",a[n]);
	
	for(i=3;i<=n;i++)
	{
		a[i]=a[i-1]%10007+a[i-2]%10007;
		printf("a[%d] : %d  ",i,a[i]);
	}
	printf("\n a[n] %d",a[n]);
	return 0;
}
*/ 
