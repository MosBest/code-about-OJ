#include <stdio.h> 

int getSum(int a, int b) 
{
	int c=-1;
	c=a;
	a=a & b;
	b=c|b;
	
	for(;a!=0;)
	{
		c=a;
		a=a & b;
		b=c|b;
		printf("%d,%d,",a,b);
	}
	return b;
	//if(c==0)
	//	return d;
	//return getSum(c,d);
	//return c+d;
}


int main(void)
{
	int a=400;
	int b=123;
	int q=-1;
	q=getSum(a,b);
	
	printf("%d",q);
	return 0;
}
