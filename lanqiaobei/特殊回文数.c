#include<stdio.h>

int main()
{
	int n=0;
	int i=10000;
	int a[6]={0};
	int num=0;//值为5或者6，表示i是5位数，还是6位数 
	int k=0;
	int j=0;
	int b=0;
	
	scanf("%d",&n);
	for(i=10000;i<1000000;i++)
	{
		a[0]=i%10;
		a[1]=i/10%10;
		a[2]=i/100%10;
		a[3]=i/1000%10;
		a[4]=i/10000%10;
		a[5]=i/100000%10;
		
		num=6;
		k=5;
		while(a[k]==0)//表示i是5位数，还是6位数
		{
			num=k;
			k--;
		}
		
		for(j=0;j<num;j++)//将数组i倒过来 
		{
			b=b*10+a[j];
		}
		
		if(i==b)//i==b表示i是回文数字
		{
			if(n==(a[0]+a[1]+a[2]+a[3]+a[4]+a[5]))
			{
				printf("%d\n",i);
			}
		 } 
		
		b=0;
	}
	
	
	return 0;
}
