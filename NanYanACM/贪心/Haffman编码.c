#include<stdio.h>
#include<malloc.h>

struct data{
	char ch;
	int weight;
};

struct node{
	struct node* left;
	struct node* right;
	char ch;
};
void kuaipai(struct data* a,int l,int r,int flag);
void paixu(struct data*a,n);
int main()
{
	int n=0,i=1,m=0;
	struct data* a=0;
	struct node* p,q;
	while(scanf("%d",&n)!=EOF)
	{
		a=(struct data*)malloc(sizeof(struct data)*(n+1));
		int b[n+1];
		for(i=1;i<=n;i++)
		{
			getchar();
			scanf("%c%d",&a[i].ch,&a[i].weight);
		}
		
		
		paixu(a,1,n);
		m=n;
		for(j=1;j<=n-1;j++)
		{
			p=(struct node*)malloc(sizeof(struct node)*1);
			q=(struct node*)malloc(sizeof(struct node)*1);
			p.ch=a[m].ch;
			p.left=null;
			p.right=null;
			
			q.ch=a[m-1].ch;
			q.left=null;
			q.right=null;
			
			m=m-2;
		}
		
	}
	return 0;
}
void kuaipai(struct data* a,int l,int r,int flag)
{
	int i=l,j=l;
	char x='\0';
	int y=0;
	int k;
	int c;
	int boo;
	
	if(flag==0)
	{
		k=a[r].weight;
	}
	else
	{
		c=a[r].ch;
	}
	
	if(l>=r)
		return;
	
	for(i=l;i<=r-1;i++)
	{
		if(flag==0) 
		{
			boo=a[i].weight>k;
		}
		else
		{
			boo=a[i].ch>c;
		}
		
		if(boo)
		{
			x=a[i].ch;
			y=a[i].weight;
			
			a[i].ch=a[j].ch;
			a[i].weight=a[j].weight;
			
			a[j].ch=x;
			a[j].weight=y;
			
			j++;
		}
	}
	
	x=a[r].ch;
	y=a[r].weight;
	
	a[r].ch=a[j].ch;
	a[r].weight=a[j].weight;
	
	a[j].ch=x;
	a[j].weight=y;
	
	kuaipai(a,l,j-1,flag);
	kuaipai(a,j+1,r,flag);
	
	return;
}

void paixu(struct data* a,n)
{
	int left;
	kuaipai(a,1,n,0);
		
	left=1;
	for(i=2;i<=n;i++)
	{
		if(a[i+1].ch==a[left].ch)
		{
			continue;
		}
		kuaipai(a,left,i-1,1);
		left=i;
	}
	return;
}
