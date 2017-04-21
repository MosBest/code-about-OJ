#include<iostream> 
#include<cstdio>
#include<cstring>
#include<stack>
#include<cmath>
using namespace std;
bool minchar(char S,char F )
{
	if((S==')' ) && (F=='+' || F=='-' || F=='*' || F=='/') )
		return true; 
	if((S=='+' || S=='-') && (F=='+' || F=='-' || F=='*' || F=='/') )
		return true;
	if((S=='*' || S=='/') && ( F=='*' || F=='/') )	
		return true;
	
	return false;
}
int main()
{
	int n;
	scanf("%d",&n);
	char s[10001];
	for(int i=0;i<n;i++) 
	{
		scanf("%s",s);
		int l=strlen(s);
		s[l+1]='\0';
		s[l]=s[l-1];
		s[l-1]=')';
		int j=0;
		int flag=0;
		stack<double> a;
		stack<char> b;
		b.push('(');
		while(s[j]!='=')
		{
			//if(a.size()>0)
			//	printf("%lf\n",a.top());
			if(s[j]>='0'&&s[j]<='9')
			{
				if(a.size()>0 && s[j-1]=='.')
				{
					double x=a.top();
					a.pop();
					a.push(x+(s[j]-'0')*0.1);
					flag++;
					j++;
					continue;
				}
				else if(b.top()=='.')
				{
					double x=a.top();
					a.pop();
					a.push(x+(s[j]-'0')*pow(0.1,flag));
					flag++;
					j++;
					continue;
				}
				
				if(a.size()>0 && s[j-1]>='0'&&s[j-1]<='9')
				{
					double x=a.top();
					a.pop();
					a.push(x*10+(s[j]-'0'));
					j++;
				}
				else
				{
					a.push(s[j]-'0');
					j++; 
				}
				continue;
			}
			
			if(s[j]=='.')
			{
				flag=1;
				b.push(s[j]);
				j++;
				continue;
			}
			
			if(b.top()=='.')
			{
				b.pop();
				flag=0;
			}
				
			
			if(s[j]=='(')
			{
				if(b.top())
				b.push(s[j]);
				j++;
				continue;
			}
			
			if(s[j]==')' && b.top()=='(')
			{
				b.pop();
				j++;
				continue;
			}
			
			if(s[j]=='+'|| s[j]=='-'|| s[j]=='*'|| s[j]=='/' || s[j]==')')
			{
				if( b.size()>0&& minchar(s[j],b.top()))
				{
					double A=a.top(); a.pop();
					double B=a.top(); a.pop();
					char C=b.top(); b.pop();
					switch(C)
					{
						case '+': a.push(A+B);break;
						case '-': a.push(B-A);break;
						case '*': a.push(A*B);break;
						case '/': a.push(B/A);break;
					}
				}
				else
				{
					b.push(s[j]);
					j++;
				}
			}
		}
		printf("%0.2lf\n",a.top());
	}
	return 0;
}
