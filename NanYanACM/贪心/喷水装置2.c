#include<stdio.h> 
#include<math.h>
#include<malloc.h>
struct data{
	int left;
	int right;
};

void allocate(struct data* a,int n,int LEN);
void kuaipai(struct data* a,int l,int r);
int main()
{
	int LEN=0;
	int WID=0;
	int m=0,n=0;
	int i=0,j=0,k=1;
	int x=0,r=0;
	struct data* a=0;
	int num=0;//存储r>WID/2的个数 
	scanf("%d",&m);
	for(i=1;i<=m;i++) 
	{
		scanf("%d%d%d",&n,&LEN,&WID);
		WID=WID/2;
		a=(struct data*)malloc(sizeof(struct data)*(n+1));
		num=n;//num是n去除r<WID/2 后的个数 
		k=1;
		for(j=1;j<=n;j++)
		{
			scanf("%d%d",&x,&r);
			if(r<WID)
			{
				num--;
				continue;
			}
			a[k].left=x-sqrt(r*r-WID*WID);
			a[k].right=x+sqrt(r*r-WID*WID);
			k++;
		}
		
		kuaipai(a,1,num);//按照right的大小从大到小排序 
		
		allocate(a,num,LEN);
	}
	
	return 0;
}

void allocate(struct data* a,int n,int LEN)
{
	int i=1;
	int jishu=0;
	int leave=0;
	
	while(leave<LEN && jishu<=n)
	{
		for(i=1;i<=n;i++) 
		{
			if(a[i].left<=leave)
			{
				leave=a[i].right;
				break;
			}
		}
		jishu++;
	}
	if(jishu<=n)
	{
		printf("%d\n",jishu);
	}
	else
	{
		printf("%d\n",0);
	}
	return;
	
}
void kuaipai(struct data* a,int l,int r)
{
	int i=l,j=l;
	int k=a[r].right;
	int y=0;
	int x=0;
	if(l>=r)
		return;
	
	for(i=l;i<=r-1;i++)
	{
		if(a[i].right>k)
		{
			y=a[i].right;
			x=a[i].left;
			
			a[i].left=a[j].left;
			a[i].right=a[j].right;
			
			a[j].right=y;
			a[j].left=x;
			j++;
		}
	}
	
	y=a[j].right;
	x=a[j].left;
			
	a[j].left=a[r].left;
	a[j].right=a[r].right;
			
	a[r].right=y;
	a[r].left=x;
	
	
	kuaipai(a,l,j-1);
	kuaipai(a,j+1,r);
	return;
}


