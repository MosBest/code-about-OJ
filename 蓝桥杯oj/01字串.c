#include<stdio.h> 

int main()
{
	int i,j,k,m,n;
	char a[6];
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			for(k=0;k<2;k++)
			{
				for(m=0;m<2;m++)
				{
					for(n=0;n<2;n++)
					{
						a[0]=i%2+'0';
						a[1]=j%2+'0';
						a[2]=k%2+'0';
						a[3]=m%2+'0';
						a[4]=n%2+'0';
						a[5]='\0';
						printf("%s\n",a);
					}
				}
			}
		}
	}
	return 0;
}
