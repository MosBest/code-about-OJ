#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		char s[600];
		scanf("%s",s);
		stack<int> A;//由于没有负数，所以令-1表示字符串"max" ,-2表示字符串"min",-3表示"("
		int l=strlen(s);
		for(int j=0;j<l;j++)
		{
			if(s[j]=='a') //-4表示add
			{
				A.push(-4);
				j=j+2;
				continue;
			}
			if(s[j]=='m'&&s[j+1]=='a')
			{
				A.push(-1);
				j=j+2;//for还会加一个1 
				continue;
			}
			else if(s[j]=='m'&&s[j+1]=='i')
			{
				A.push(-2);
				j=j+2;//for还会加一个1
				continue;
			}
			else if(s[j]=='(')
			{
				A.push(-3);
				continue;
			}
			else if(s[j]==',')
			{
				continue;
			}
			else if(s[j]==')')
			{
				int B=A.top();
				A.pop();
				int C=A.top();
				A.pop();
				int D=A.top();
				A.pop();
				int E=A.top();
				A.pop();
				if(E==-1)
					A.push(max(B,C));
				else if(E==-2)
					A.push(min(B,C));
				else if(E=-4)
					A.push(B+C);
				
				continue;
			}
			int y=s[j];
			int x=0;;
			while(y>='0' && y<='9')
			{
				j++;
				x=x*10+(y-'0');
				y=s[j];
			}
			j--;
			A.push(x);
			
		}
		printf("%d\n",A.top());
		A.pop();
	}
	return 0;
}
