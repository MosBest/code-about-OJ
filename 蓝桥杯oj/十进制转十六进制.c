#include<stdio.h>
#include<math.h>

int main()
{
	int a=0;
	char b[10]={'\0'};
	scanf("%d",&a);
	printf("%X\n",a);
	//fflush(stdin);
	gets(b);
	printf("nihao :%s",b);
	
	return 0;
}
