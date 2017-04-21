#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define PI acos(-1.0)
typedef struct{
	double k[3][3];
}node;
node temp;

node Multiply(node l,char c)
{
	node f,jishu;
	jishu=temp;
	if(c=='r')
	{
		
		f=l;
		l=jishu;
		jishu=f;
	}
	memset(f.k,0,sizeof(f.k));
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
				f.k[i][j]+=l.k[i][k]*jishu.k[k][j];
		}
	}
	return f;
}
void pingyi()
{
	double a,b;
	scanf("%lf%lf",&a,&b);
	node pin;
	memset( pin.k,0,sizeof(pin.k));
	pin.k[0][0]=pin.k[1][1]=pin.k[2][2]=1;
	pin.k[0][2]=a;
	pin.k[1][2]=b;
	temp=Multiply(pin,'l');
}

void Xfanzhuan()
{
	node pin;
	memset( pin.k,0,sizeof(pin.k));
	pin.k[0][0]=pin.k[2][2]=1;
	pin.k[1][1]=-1;
	temp=Multiply(pin,'l');
}

void Yfanzhuan()
{
	node pin;
	memset( pin.k,0,sizeof(pin.k));
	pin.k[1][1]=pin.k[2][2]=1;
	pin.k[0][0]=-1;
	temp=Multiply(pin,'l');
}

void Pbei()
{
	double P;
	scanf("%lf",&P);
	node pin;
	memset( pin.k,0,sizeof(pin.k));
	pin.k[0][0]=pin.k[1][1]=P;
	pin.k[2][2]=1;
	temp=Multiply(pin,'l');
}
void Axzhuan()
{
	double A;
	scanf("%lf",&A);
	node pin;
	A=A*PI/180; 
	memset( pin.k,0,sizeof(pin.k));
	pin.k[0][0]=pin.k[1][1]=cos(A);//注意了，在c/c++中,cos(A) 里面天的应该是弧度，要把角度化成弧度才能正确 
	pin.k[0][1]=-sin(A);
	pin.k[1][0]=sin(A);
	pin.k[2][2]=1;
	temp=Multiply(pin,'l');
}

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	double a[3][N];
	for(int i=0;i<N;i++)
	{
		scanf("%lf%lf",&a[0][i],&a[1][i]);
		a[2][i]=1;
	}
	memset( temp.k,0,sizeof(temp.k));
	temp.k[0][0]=1;
	temp.k[1][1]=1;
	temp.k[2][2]=1;
	char c;
	for(int i=0;i<M;i++)
	{
			getchar();
			scanf("%c",&c);
			//printf("c %c\n",c);
			switch(c)
			{
				case 'M':pingyi();break;
				case 'X':Xfanzhuan();break;
				case 'Y':Yfanzhuan();break;
				case 'S':Pbei();break;
				case 'R':Axzhuan();break;
			}
			
	}
	//printf("cos 180 %lf   sin 180 %lf\n",cos(180),sin(180));
	node next;
	for(int i=0;i<N;i++)
	{
		memset(next.k,0,sizeof(next.k));
		next.k[0][0]=a[0][i];
		next.k[1][0]=a[1][i];
		next.k[2][0]=a[2][i];
		
		next=Multiply(next,'r');
		printf("%0.1lf %0.1lf\n",next.k[0][0],next.k[1][0]);
		
	}
	return 0;
}
