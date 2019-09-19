//闰年判断
//是4的倍数但不是100的倍数。或者是400的倍数 

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
