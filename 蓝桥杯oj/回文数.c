#include<stdio.h>

int main()
{
	int a=1001;
	int i=0;
	int j=0;
	for(i=1;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			printf("%d\n",a*i+110*j);
		}
	}
	return 0;
}
