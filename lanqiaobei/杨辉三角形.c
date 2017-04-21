#include<stdio.h> 

int main()
{
	int n=0;
	int a[34][34]={0};
	int j=0;
	int i=0;
	scanf("%d",&n); 
	a[0][0]=1;
	if(n==1)
	{
		printf("%d",1);
		return 0;
	}
	printf("%d\n",1);
	for(i=1;i<n;i++)
	{
		for(j=1;j<i;j++)
		{
			a[i][j]=a[i-1][j-1]+a[i-1][j];
		}
		a[i][0]=1;
		a[i][j]=1;
		
		for(j=0;j<=i;j++)//Êä³öµÚiÐÐ 
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
		
	}
	
	return 0;
}
