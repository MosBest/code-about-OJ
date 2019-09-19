#include<stdio.h>
#include<string.h>

void push(char* a, char c);
char pop(char* a);
char head(char* a);
int main()
{
	char s[200]={0};
	char a[200]={0};
	char b[200]={0};
	int l=0;
	int i=0;
	int k1=0,k2=0;
	gets(s);
	b[0]=a[0]='0';//a和b的 零号位 表示堆顶部的坐标 。总是指向最后一个有效字符 
	l=strlen(s);
	s[l]=')';
	s[l+1]='\0';
	if(s[0]>='0' && s[0]<='9')
	{
		push(a,s[0]);
	}
	
	for(i=1;i<=l-1;i++)
	{
		if(s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' )
		{
			push(b,s[i]);
		}
		if(s[i]==')')
		{
			//pop(b);
			while(b[b[0]-'0']!='(')
			{		
				k1=pop(a)-'0';
				k2=pop(a)-'0';
				switch(pop(b))
				{
				case '+':push(a,(k2+k1)+'0');break;
				case '-':push(a,(k2-k1)+'0');break;
				case '*':push(a,(k2*k1)+'0');break;
				case '/':push(a,(k2/k1)+'0');break;
				}
			}
			
			pop(b);
		}
		if(s[i]>='0' && s[i]<='9')
		{
			if(s[i-1] == '*' || s[i-1]=='/')
			{
				while(head(b) == '*' || head(b) =='/')
				{
					k1=s[i]-'0';
					k2=pop(a)-'0';
					switch(pop(b))
					{
						case '*':push(a,(k2*k1)+'0');break;
						case '/':push(a,(k2/k1)+'0');break;
					}
				}
			}		
			else
			{
				if(s[i-1]=='(')
				{
					push(a,s[i]);
				}
				else
				{
					if(s[i+1] == '+' || s[i+1] == '-' || s[i+1] ==')' )
					{
						k1=s[i]-'0';
						k2=pop(a)-'0';
						switch(pop(b))
						{
							case '+':push(a,(k2+k1)+'0');break;
							case '-':push(a,(k2-k1)+'0');break;
						}
					}
					else
					{
						if(s[i+1]=='*' || s[i+1]=='-')
						{
							push(a,s[i]);
						}
					}
				}
			}
		}
		
	}
	
	while(b[0]!='0')
	{
		k1=pop(a)-'0';
		k2=pop(a)-'0';
		switch(pop(b))
		{
			case '+':push(a,(k2+k1)+'0');break;
			case '-':push(a,(k2-k1)+'0');break;
			case '*':push(a,(k2*k1)+'0');break;
			case '/':push(a,(k2/k1)+'0');break;
		}
		
	}
	printf("%d\n",a[1]-'0');
	printf("%d",2-3*(9-1-2*3*3-2*2*(4-6))*3);
	return 0;
}

void push(char* a, char c)
{
	int i=a[0]-'0';
	a[i+1]=c;
	a[0]=a[0]+1;
	return;
}

char pop(char* a)
{
	char x=a[a[0]-'0'];
	a[0]=a[0]-1;
	return x;
}
char head(char* a)
{
	return a[a[0]-'0'];
}
