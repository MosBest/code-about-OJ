#include<iostream> 
#include<cstdio>
#include<stack>
#include<cstring> 

using namespace std;
bool A[9][9];
bool B[9][9];
bool C[9][9];
bool D[9][9];
bool visited[9][9];
typedef struct{
	int x;
	int y;
	int data;
}node;

void inser(int i,int j,int zh,bool b)
{
	if(i>=0&&i<3)
	{
		if(j>=0&&j<3)
			C[0+(zh-1)/3][0+(zh-1)%3] =b;
		if(j>=3&&j<6)
			C[0+(zh-1)/3][3+(zh-1)%3] =b;
		if(j>=6&&j<9)
			C[0+(zh-1)/3][6+(zh-1)%3] =b;
	}
	else if(i>=3&&i<6)
	{
		if(j>=0&&j<3)
			C[3+(zh-1)/3][0+(zh-1)%3] =b;
		if(j>=3&&j<6)
			C[3+(zh-1)/3][3+(zh-1)%3] =b;
		if(j>=6&&j<9)
			C[3+(zh-1)/3][6+(zh-1)%3] =b;
	}
	else if(i>=6&&i<9)
	{
		if(j>=0&&j<3)
			C[6+(zh-1)/3][0+(zh-1)%3] =b;
		if(j>=3&&j<6)
			C[6+(zh-1)/3][3+(zh-1)%3] =b;
		if(j>=6&&j<9)
			C[6+(zh-1)/3][6+(zh-1)%3] =b;
	}
}


bool banduanC(int i,int j,int zh)
{
	if(i>=0&&i<3)
	{
		if(j>=0&&j<3)
			return C[0+(zh-1)/3][0+(zh-1)%3] ;
		if(j>=3&&j<6)
			return C[0+(zh-1)/3][3+(zh-1)%3] ;
		if(j>=6&&j<9)
			return C[0+(zh-1)/3][6+(zh-1)%3];
	}
	else if(i>=3&&i<6)
	{
		if(j>=0&&j<3)
			return C[3+(zh-1)/3][0+(zh-1)%3] ;
		if(j>=3&&j<6)
			return C[3+(zh-1)/3][3+(zh-1)%3] ;
		if(j>=6&&j<9)
			return C[3+(zh-1)/3][6+(zh-1)%3];
	}
	else if(i>=6&&i<9)
	{
		if(j>=0&&j<3)
			return C[6+(zh-1)/3][0+(zh-1)%3] ;
		if(j>=3&&j<6)
			return C[6+(zh-1)/3][3+(zh-1)%3] ;
		if(j>=6&&j<9)
			return C[6+(zh-1)/3][6+(zh-1)%3];
	}
}


int findmin(int x,int y,int mis)
{
	if(visited[x][y]==true)
		return D[x][y];
	for(int i=1;i<=9;i++)
	{
		if(A[x][i%9]==false && A[i%9][y] == false && banduanC(x,y,i))
		{
			A[x][i%9]=true;
			A[i%9][y]=true;
			inser(x,y,i,true);
			return i;
		}
	}
	return -2;
}


void dfs()
{
	stack<node> mystack;
	memset(A,false,sizeof(A));
	memset(B,false,sizeof(B));
	memset(C,false,sizeof(C));
	memset(visited,false,sizeof(visited));
	node pr,next;
	int c=0;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(D[i][j]!=0)
			{
				A[i][D[i][j]%9]=true;
				B[D[i][j]][j%9]=true;
				inser(i,j,D[i][j],true);
				visited[i][j]=true;
			}
			else
				c++;
		}
	}
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			printf("%d ",D[i][j]);
		printf("\n");
	}
	printf("asd\n");
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			printf("%d ",A[i][j]);
		printf("\n");
	}
	printf("asd\n");
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			printf("%d ",B[i][j]);
		printf("\n");
	}
	printf("asd\n");
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			printf("%d ",C[i][j]);
		printf("\n");
	}
	printf("asd\n");
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			printf("%d ",visited[i][j]);
		printf("\n");
	}
	printf("asd\n");
	int i;
	int j;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(D[i][j]==0)
				break;
		}
	}
	
	pr.x=i;
	pr.y=j;
	pr.data=findmin(pr.x,pr.y,0);
	D[pr.x][pr.y]=pr.data;
	mystack.push(pr);
	
	while(mystack.size()<c)
	{
		next=mystack.top();
		if(next.y>=8)
		{
			pr.x=next.x+1;
			pr.y=0;
			pr.data=findmin(pr.x,pr.y,D[pr.x][pr.y]);
			D[pr.x][pr.y]=pr.data;
		}
		else
		{
			pr.x=next.x;
			pr.y=next.y+1;
			pr.data=findmin(pr.x,pr.y,D[pr.x][pr.y]);
			D[pr.x][pr.y]=pr.data;
		}
		while(visited[pr.x][pr.y]==-1)
		{
			next=pr;
			if(next.y>=8)
			{
				pr.x=next.x+1;
				pr.y=0;
				pr.data=findmin(pr.x,pr.y,D[pr.x][pr.y]);
				D[pr.x][pr.y]=pr.data;
			}
			else
			{
				pr.x=next.x;
				pr.y=next.y+1;
				pr.data=findmin(pr.x,pr.y,D[pr.x][pr.y]);
				D[pr.x][pr.y]=pr.data;
			}
		}
		
		if(pr.data!=-2)
			mystack.push(pr);
		else
			while(next.data!=-2)
			{
				A[pr.x][D[pr.x][pr.y]%9]=false;
				B[D[pr.x][pr.y]%9][pr.y]=false;
				inser(pr.x,pr.y,D[pr.x][pr.y],false);
				D[pr.x][pr.y]=0;
				
				next.data=findmin(next.x,next.y,D[next.x][next.y]);
				if(next.data==-2)
				{
					pr=next;
					mystack.pop();
					next=mystack.top();
				}
				else
					break;
			}
	}
	
	return;
}


int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<9;j++)
		{
			for(int k=0;k<9;k++)
			{
				scanf("%d",&D[j][k]);
			}
		}
		printf("asd\n");
		dfs();
	}
	return 0;
}
