#include<stdio.h>
#include<malloc.h>

int main()
{
	int n=0;//行数 
	int m=0;//列数 
	int i=0;
	int j=0;
	char* c=0;
	scanf("%d %d",&n,&m);
	c=(char*)malloc(sizeof(char)*(m+1));
	
	
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<=i;j++) //A左边 
		{
			c[j]='A'+(i-j);
		}
		
		for(j=i+1;j<m;j++)//A右边
		{
			c[j]='A'+(j-i);
		}
		c[m]='\0';
		printf("%s\n",c);
	}
	return 0;
}

//注意：一开始提交的代码的结果为 90% ，评价结果为 运行错误。 
//后观测错误的原因是，在行数大于列数的情况，即n>m时，
//原先使用的代码在计算A左边 时，是
 //for(j=0;j<=i;j++) //A左边 
//		{
//			c[j]='A'+(i-j);
//		}
//即，从右向左填矩阵。当n>m，时，就有可能导致A离开矩阵，那么如果依然在填写A左边是从A开始，从右向左的话，就会导致越界现象。 
