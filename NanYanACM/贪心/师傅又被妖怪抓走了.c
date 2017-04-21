#include<stdio.h>

typedef struct{
	int x;
	int y;
	int temp;
}node;
char s[120][120];
bool visited[120][120];
node houzhi;
int n,m,T;
void yuchuli(int i,int j,char type)
{
	for(i=i+1,j=j;i<=n;i++)
	{
		if(s[i][j]=='X' || s[i][j]=='S')
			break;
		if((s[i][j]=='D' && type=='E') || s[i][j]=='E' && type=='D')
			s[i][j]=b;
		else
			s[i][j]=tpye;
	}
	
	for(i=i-1,j=j;i>=1;i--)
	{
		if(s[i][j]=='X' || s[i][j]=='S')
			break;
		if((s[i][j]=='D' && type=='E') || s[i][j]=='E' && type=='D')
			s[i][j]=b;
		else
			s[i][j]=tpye;
	}
	
	for(i=i,j=j+1;j<=m;j++)
	{
		if(s[i][j]=='X' || s[i][j]=='S')
			break;
		if((s[i][j]=='D' && type=='E') || s[i][j]=='E' && type=='D')
			s[i][j]=b;
		else
			s[i][j]=tpye;
	}
	
	for(i,j=j-1;i>=1;j--)
	{
		if(s[i][j]=='X' || s[i][j]=='S')
			break;
		if((s[i][j]=='D' && type=='E') || s[i][j]=='E' && type=='D')
			s[i][j]=b;
		else
			s[i][j]=tpye;
	}
}

void brf()
{
	node Q[200];
	push(Q,houzhi);
	houzhi.temp=0;
	while
	
	return;
}



int main()
{
	
	int i,j;
	
	while(scanf("%d%d%d",&n,&m,&T)!=EOF)
	{
		int(i=1;i<=n;i++)
			scanf("%s",s[i]);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(s[i][j]=='S')
				{
					houzhi.x=i;
					houzhi.y=j;
				}
				if(s[i][j]=='E') 
					yuchuli(i,j,'E');
				else if(s[i][j]=='D') 
					yuchuli(i,j,'D');
			}
		}
		printf("Case %d:",i);
		
		brf();
	}
	return 0;
}
