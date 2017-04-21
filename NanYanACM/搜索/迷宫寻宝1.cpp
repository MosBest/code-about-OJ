#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

typedef struct{
	int x;
	int y;
}node;
node door[5];
int key[5];
int num[5];
int M,N;
char s[50][50];
bool visited[50][50];
queue<node> q;
void ergodic(node pr)
{
	node D;
	D.x=pr.x;
	D.y=pr.y+1;
	if(D.y<N && visited[D.x][D.y]==false && s[D.x][D.y]!='X')
	{
		visited[D.x][D.y]=true;
		//s[D.x][D.y]='X';
		q.push(D);
	}
	
	D.x=pr.x;
	D.y=pr.y-1;
	if(D.y>=0 && visited[D.x][D.y]==false && s[D.x][D.y]!='X')
	{
		visited[D.x][D.y]=true;
		//s[D.x][D.y]='X';
		q.push(D);
	}

	D.x=pr.x+1;
	D.y=pr.y;
	if(D.x<M  && visited[D.x][D.y]==false && s[D.x][D.y]!='X')
	{
		visited[D.x][D.y]=true;
		//s[D.x][D.y]='X';
		q.push(D);
	}
	
	D.x=pr.x-1;
	D.y=pr.y;
	if(D.x>=0 && visited[D.x][D.y]==false && s[D.x][D.y]!='X')
	{
		visited[D.x][D.y]=true;
		//s[D.x][D.y]='X';
		q.push(D);
	}
	
	return;
}

void BFS(int sx,int sy)
{
	memset(visited,false,sizeof(visited));
	memset(key,0,sizeof(key));
	
	for(int i=0;i<5;i++)
	{
		door[i].x=-1;
		door[i].y=-1;
	}
	while(!q.empty())
		q.pop();
	node head;
	head.x=sx;
	head.y=sy;
	q.push(head);
	visited[sx][sy]=true;
	//s[sx][sy]='X';
	while(!q.empty())
	{
		node pr=q.front();
		q.pop();
		char c=s[pr.x][pr.y];
		if(s[pr.x][pr.y]=='G')
		{
			printf("YES\n");
			return; 
		}
		if(c=='a' || c=='b' || c=='c' || c=='d' || c=='e' )
		{
			key[c-'a']++;
			visited[pr.x][pr.y]=true;
			ergodic(pr);
			if(key[c-'a']==num[c-'a'] && door[c-'a'].x!=-1 && door[c-'a'].y!=-1 )//表明之前已经访问过这个门，只是由于没有钥匙将其存储起来了，现在可以用了 
			{
				//s[door[c-'a'].x][door[c-'a'].y]='X';
				visited[door[c-'a'].x][door[c-'a'].y]=true;
				pr.x=door[c-'a'].x;
				pr.y=door[c-'a'].y;
				ergodic(pr);
			}
			continue;
		}
		
		if(c=='A' || c=='B' || c=='C' || c=='D' || c=='E' )
		{
			door[c-'A'].x=pr.x;
			door[c-'A'].y=pr.y;
			if(key[c-'A']==num[c-'A'])
			{
				visited[door[c-'A'].x][door[c-'A'].y]=true;
				pr.x=door[c-'A'].x;
				pr.y=door[c-'A'].y;
				ergodic(pr);
			}
			continue;
		}
		
		ergodic(pr);	
	}
	printf("NO\n");
	return;
}
int main()
{
	
	while(scanf("%d %d",&M,&N)!=EOF && M!=0 && N!=0)
	{
		getchar();
		
		for(int i=0;i<M;i++)
		{
			gets(s[i]);
		//	puts(s[i]);
			//printf("%d\n",i);
		}
		memset(num,0,sizeof(num));
		int sx,sy;
		for(int i=0;i<M;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(s[i][j]=='S')
				{
					sx=i;
					sy=j;
				}
				else if(s[i][j]=='a' ||s[i][j]=='b' || s[i][j]=='c' || s[i][j]=='d' || s[i][j]=='e')
				{
					num[s[i][j]-'a']++;
				}
			}
		}
		
		BFS(sx,sy);
	}
	return 0;
}
