#include<stdio.h>
#include <iostream>
#include <algorithm>
#include<string.h>
using namespace std;

typedef struct{
	int x;
	int y;
	int temp;
}node;
char s[120][120];

int ans=0x3f3f3f3f;
int a[4][2]={{1,0} , {-1,0} , {0,1} , {0,-1}};
node houzhi;
int n,m,T;
void yuchuli(int i,int j,char type)
{
	int i1=i,j1=j;
	for(i=i1+1,j=j1;i<n;i++)
	{
		if(s[i][j]=='X' ||s[i][j]=='D' ||s[i][j]=='E')
			break;
		if((s[i][j]=='d' && type=='e') || (s[i][j]=='e' && type=='d'))
			s[i][j]='b';
		else
			s[i][j]=type;
	}
	
	for(i=i1-1,j=j1;i>=0;i--)
	{
		if(s[i][j]=='X' ||s[i][j]=='D' ||s[i][j]=='E')
			break;
		if((s[i][j]=='d' && type=='e') || (s[i][j]=='e' && type=='d'))
			s[i][j]='b';
		else
			s[i][j]=type;
	}
	
	for(i=i1,j=j1+1;j<m;j++)
	{
		if(s[i][j]=='X' ||s[i][j]=='D' ||s[i][j]=='E')
			break;
		if((s[i][j]=='d' && type=='e') || (s[i][j]=='e' && type=='d'))
			s[i][j]='b';
		else
			s[i][j]=type;
	}
	
	for(i=i1,j=j1-1;j>=0;j--)
	{
		if(s[i][j]=='X' ||s[i][j]=='D' ||s[i][j]=='E')
			break;
		if((s[i][j]=='d' && type=='e') || (s[i][j]=='e' && type=='d'))
			s[i][j]='b';
		else
			s[i][j]=type;
	}
}

void init(node* Q)
{
	Q[0].x=0;
	Q[0].y=1;
}

node fraint(node* Q)
{
	
	return Q[Q[0].x+1];
}

void pop(node* Q)
{
	Q[0].x++;
}

void push(node* Q, node no)
{
	Q[Q[0].y]=no;
	Q[0].y++;
}

bool NotEmply(node* Q)
{
	if(Q[0].x==Q[0].y-1)
		return false;
	return true;
}

bool legalBound(node next) 
{
	if(next.x>=0 && next.x<n && next.y>=0 && next.y<m)
		return true;
	return false;
	
}
bool ableGet(node next)
{
	if(s[next.x][next.y] == 'X' || s[next.x][next.y] == 'E' || s[next.x][next.y] == 'D')
		return false;
	return true;
}



int __brf(node tem,char type)
{
	int i=0;
	node Q1[400];
	node next;
	bool visited[120][120];
	memset 	(visited,false,sizeof(visited)); 
	init(Q1);
	push(Q1,tem);
	visited[tem.x][tem.y]=true;
	while(NotEmply(Q1))
	{
		tem=fraint(Q1);
		pop(Q1);
		if(s[tem.x][tem.y]=='b')
		{
			return tem.temp;
			
		}
		
		if((s[tem.x][tem.y]=='d' && type=='e') || (s[tem.x][tem.y]=='e' && type=='d'))
		{
			return tem.temp;
		}
		
		for(i=0;i<4;i++)
		{
			next.x=tem.x+a[i][0];
			next.y=tem.y+a[i][1];
			next.temp=tem.temp+1;
			if(legalBound(next) && ableGet(next) && !visited[next.x][next.y] && ans>tem.temp)
			{
				push(Q1,next);
				visited[next.x][next.y]=true;
			}
			
		}
	}
	return ans;
}

void brf()
{
	int i;
	node Q[400];
	bool visited[120][120];
	memset(visited,false,sizeof(visited)); 
	node tem,next;
	init(Q);
	push(Q,houzhi);
	houzhi.temp=0;
	visited[houzhi.x][houzhi.y]=true;
	while(NotEmply(Q))
	{
		tem=fraint(Q);
		pop(Q);
		if(s[tem.x][tem.y]=='b')
		{
			ans=min(ans,tem.temp);
		}
		
		if(s[tem.x][tem.y]=='d' || s[tem.x][tem.y]=='e')
		{
			ans=min(ans,__brf(tem,s[tem.x][tem.y]));
		}
		
		for(i=0;i<4;i++)
		{
			next.x=tem.x+a[i][0];
			next.y=tem.y+a[i][1];
			next.temp=tem.temp+1;
			if(legalBound(next) && ableGet(next) && !visited[next.x][next.y] && ans>tem.temp)
			{
				push(Q,next);
				visited[next.x][next.y]=true;
			}
			
		}
	}
		
	if(T<ans)
		printf("%d\n",-1);
	else
		printf("%d\n",ans);
	return ;
}



int main()
{
	
	int i,j;
	int k=0;
	
	while(scanf("%d%d%d",&n,&m,&T)!=EOF)
	{ 
		ans=0x3f3f3f3f;
		k++;
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(s[i][j]=='S')
				{
					houzhi.x=i;
					houzhi.y=j;
					break;
				}
			}
		}
		

					
					
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(s[i][j]=='E') 
					yuchuli(i,j,'e');
				else if(s[i][j]=='D') 
					yuchuli(i,j,'d');
			}
		}
		
		printf("Case %d:\n",k);
		
		brf();
	}
	return 0;
}
