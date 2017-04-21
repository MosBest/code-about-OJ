/*
//方法一：运用递归，但是当运算到n=30时，就不行了，更别说n=1000000。
//所以，递归在oj最好不用 
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

//方法二：非递归 式的Fibonacci 数列
//利用(a%c+b%c)%c=(a+b)%c
//根据F(n)=F(n-1)+F(n-2),用数组的形式存储F(n),在for循环里一步步计算，比递归要快好多 
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
		a[i]=(a[i-1]+a[i-2])%10007;//或者 a[i]=(a[i-1]%10007+a[i-2]%10007)%10007
	}
	printf("%d",a[n]);
	return 0;
}

//遇到的问题
//问题一 ：在运用递归方式提交结果时，成绩为30% 
//问题二：非递归提交，结果为60%
//错误原因：for循环里写的是 a[i]=a[i-1]%10007+a[i-2]%10007; 。看似正确，其实
//有问题。运用下面代码，将a[1~n] 所有的数据打印出来，发现n<=23时，没有问题，因为
//a[22],a[11] 的 Fibonacci数列和小于10007，所以a[22]%10007+a[21]%10007 等于 (a[22]+a[21])%10007
//但是当计算n==24 时，a[22]<10007,a[23]<10007,则 a[22]%10007+a[23]%10007=a[22]+a[23]>10007，错误。
//所以最终形式应该写为 a[i]=(a[i-1]%10007+a[i-2]%10007)%10007;或者 a[i]=(a[i-1]+a[i-2])%10007;
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
