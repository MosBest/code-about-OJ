//函数里的局部变量，即使是malloc创建的，出函数时，也被销毁了
#include<stdio.h> 
#include<malloc.h>
struct jieguo MAX(int* c,int n,long long int** a);

struct jieguo{
	long long int zhiyuan;
	int flag;
};

int main()
{
	int n=0;
	long long int a1=0,x=0,y=0;
	int k=0,m=0;
	int i=0,j=0;
	scanf("%d",&n);
	long long int* a[n+1];
	struct jieguo* b=0;
	int c[n+1];//作为下标 
	int number=0;
	int num=0;
	struct jieguo max;
	//存储输入数据 
	for(i=1;i<=n;i++)
	{
		scanf("%d%I64d%I64d%I64d%d",&k,&a1,&x,&y,&m);
		a[i]=(long long int*)malloc(sizeof(long long int)*(k+1));
		a[i][0]=k;//存储第i的专家问题的个数 
		a[i][1]=a1;
		number+=k;//number记录所有专家的所有问题的个数 
		for(j=2;j<=k;j++)
		{
			a[i][j]=(a[i][j-1]*x+y)%m;
		}
	}
	
	
	b=(struct jieguo*)malloc(sizeof(struct jieguo)*(number+1));
	for(i=0;i<=n;i++)
	{
		c[i]=1;
	}

	for(i=1;i<=number;i++)
	{
		max=MAX(c,n,a);
		b[i].flag=max.flag;
		b[i].zhiyuan=max.zhiyuan;
	}
	
	for(i=2;i<=number;i++)
	{
		if(b[i].zhiyuan<b[i-1].zhiyuan)
		{
			num++;
		}
	}
	printf("%d\n",num);
	
	for(i=1;i<=number;i++)
	{
		
		printf("%d %d\n",b[i].zhiyuan,b[i].flag);
	}
	
	return 0;
}

struct jieguo MAX(int* c,int n ,long long int** a)
{
	int i=1;
	struct jieguo b;
	for(i=1;i<=n;i++)
	{
		if(c[i]<=a[i][0])
		{
			b.zhiyuan=a[i][c[i]];
			b.flag=i;
			break;
		}
	}

	
	for(;i<=n;i++)
	{
		if(c[i]<=a[i][0] && a[i][c[i]]<=b.zhiyuan)
		{
			b.zhiyuan=a[i][c[i]];
			c[i]++;
			b.flag=i;
		}
	}
	
	return b;
} 
