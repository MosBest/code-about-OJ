#include<stdio.h>
#define PI 3.14159265358979323

int main()
{
	int n=0;
	double area=0.0; 
	scanf("%d",&n);
	area=PI*n*n;
	printf("%0.7lf",area);
	
	return 0;
}

//
//问题一：强制类型转换中，是(int)(a)，而不是int(a) 
//问题二： 之前写了一个(int)(PI*n*n)*1e8,后来发现对于int型时，可能导致溢出 
