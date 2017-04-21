#include<stdio.h> 
#include<string.h>
int number(char* a);
int main()
{
	int i=0,j=0;
	int num=0;
	char a[5010]={0};
	char b[5010]={0};
	int len=0;
	
	while(gets(a))
	{
		
		gets(b);
		len=strlen(a);
		
		if( (len!=strlen(b)) || (number(a)!=number(b)) )
		{
			printf("%d\n",-1);
			continue;
		}
		
		
		
		i=0;
		j=0;
		num=0;
		for(i=0;i<=len-1;i++)
		{
			if(a[i]!='+')
				continue;
				
			for(j=j;j<=len-1;j++)
			{
				if(b[j]!='+')
					continue;
				if(j>i)
				{
					num+=j-i;
				}
				else
					num+=i-j;
				
				j=j+1;
				break;
			}
		}
		
		printf("%d\n",num);
	}
	
	return 0;
}
int number(char* a)
{
	int i=0;
	int l=strlen(a);
	int b=0;
	for(i=0;i<l;i++)
	{
		if(a[i]=='+')
			b++;
	}
	return b;
	
}
