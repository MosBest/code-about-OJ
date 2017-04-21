#include<iostream>
#include<cstdio>
#include<stack>
 
using namespace std;
int n=0;
int a=0,b=0;
bool NoMaoDun(stack<int> s)
{
	
	int ss[n+1][n+1];
	//stack<char> s=st;
	int size=s.size();
	int num=n;
	int i;
	for(i=1;i<=n;i++)
	{
		if(size>num)
		{
			size=size-num;
			num=num-1;
			continue;
		}
		break;
	}
	if(i==1)
		return true;
	int j=0;
	int k=size;
	j=size;
	size=i;
	for(i;i>=1;i--)
	{
		
		for(;j>=1;j--)
		{
			ss[i][j]=s.top();
			s.pop();
		}
		j=n-i+1+1;
	}
	j=k;
	for(i=size;i>=2;i--)
	{
		
		for(;j>=1;j--)
		{
			if((ss[i][j]==1 && ss[i-1][j]!=ss[i-1][j+1] ) || (ss[i][j]==0 && ss[i-1][j]==ss[i-1][j+1] ) )
				return false;
		}
		j=n-i+1+1;
	}
	return true;
}

int main()
{
	
	int flag=1;
	int num=0;
	int k;
	stack<int> mystack;
	bool qqq;
	while(scanf("%d",&n)!=EOF)
	{
		a=0;
		b=0;
		flag=1;
		num=0;
		
		if((1+n)*n/2%2==1)
		{
			printf("%d\n",0);
			continue;
		}
		
		mystack.push(1);
		a++;
		while(!mystack.empty()) 
		{
			mystack.push(1);
			a++;
			if((a+b)==(1+n)*n/2+1)
			{
				num++;
				//printf("a %d b %d \n",a,b);
				mystack.pop();
				a--;
				if(mystack.top()==1)
				{
					mystack.pop();
					a--;
					mystack.push(0);
					b++;
					flag=0;
				}
				else if(mystack.top()==0)
				{
					mystack.pop();
					b--;
					flag=0;
				}
			}
			
			if(a>(1+n)*n/4 || b>(1+n)*n/4)
						qqq=true;
				else
						qqq=!NoMaoDun(mystack);
			//qqq=!NoMaoDun(mystack);
			while((qqq || flag==0) && !mystack.empty())
			{
				flag=1;
				k=mystack.top();
				mystack.pop();
				
				if(k==0)
				{
					b--;
					flag=0;
					continue;
				}
				if(k==1)
				{
					a--;
					mystack.push(0);
					b++;
				}
				if(a>(1+n)*n/4 || b>(1+n)*n/4)
						qqq=true;
				else
						qqq=!NoMaoDun(mystack);
			}
			
		}
		printf("%d\n",num);
		
	}
	return 0;
}
