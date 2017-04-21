#include<stdio.h>

void lcm(int *s,int *b)  
{  
    *s=*s/ *b;  
}  

int main()
{
	int a=0,b=0,r=0,c=0;
	int A=0,B=0;
	scanf("%d%d",&a,&b);
	A=a*b; 
	if(a<b)
	{
		c=a;
		a=b;
		b=c;
	}

	while(a%b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	lcm(&A,&b);
	printf("%d",A);
	return 0;
}
