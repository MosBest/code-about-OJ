#include<stdio.h>

int main()
{
	int i=100;
	int a=0;
	int b=0;
	int c=0;
	for(i=100;i<1000;i++)
	{
		a=i%10;
		b=(i/10)%10;
		c=i/100;
		if(i==(a*a*a+b*b*b+c*c*c))
		{
			printf("%d\n",i);
		}
	}
	return 0;
}
