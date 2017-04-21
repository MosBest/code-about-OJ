#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>

using namespace std;
int main()
{
	stack<char> A;
	stack<double> B;
	char s[2010];
	while(gets(s))
	{
		for(int i=0;i<strlen(s);i++)
		{
			A.push(s[i]);
		}
		
		while(!A.empty())
		{
			char x=A.top();
			double f;
			A.pop();
			if(x>='0' && x<='9')//如果是数值，那么A一定不为空 
			{
				char y=A.top();
				if(y>='0' && y<='9')
				{
					f=x-'0';
					//printf("%lf ",f);
					while(y!='.')
					{
						A.pop();
						f=(y-'0')+f*0.1 ;
						//printf("%lf ",f);
						y=A.top();
					}
					//printf("y %c ",y);
					A.pop();
					y=A.top();
					//printf("y %c ",y);
					A.pop();
					f=(y-'0')+f*0.1;
					//printf("%lf\n",f);
					B.push(f);
				}
				else if(y=='.')
					{	
						A.pop();
						y=A.top();
						A.pop();
						B.push((y-'0')+(x-'0')*0.1);
					}
					else
					{
						B.push(x-'0');
					}
					
			} 
			else if(x==' ')
			{
				continue;
			}
			else if(x=='+' || x=='-' || x=='*' || x=='/')
				  {
				  	double l=B.top();
				  	B.pop();
				  	double r=B.top();
				  	B.pop();
				  	switch(x)
				  	{
				  		case '+': B.push(l+r);break;
				  		case '-': B.push(l-r);break;
				  		case '*': B.push(l*r);break;
				  		case '/': B.push(l/r);break;
					}
				  }		
		}
		
		printf("%0.2lf\n",B.top());
		B.pop();
		
	}
	return 0;
}
