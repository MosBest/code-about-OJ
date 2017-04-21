#include<stdio.h> 
#include<math.h>
#define LEN 20
#define WID 2
void allocate(double* a,int n);
void kuaipai(double* a,int l,int r);
int main()
{
	int m=0,n=0;
	int i=0,j=0;
	double a[601]={0};
	scanf("%d",&m);
	for(i=1;i<=m;i++) 
	{
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			scanf("%lf",a+j);
		}
	
		allocate(a,n);
	}
	
	return 0;
}

void allocate(double* a,int n)
{
	int i=1;
	double leave=LEN;
	double k=0;
	int wid=WID/2;
	kuaipai(a,1,n);
	while(leave>0)
	{
		k=sqrt(a[i]*a[i]-wid*wid);
		leave=leave-2*k;
		i++;
	}
	i=i-1;
	printf("%d\n",i);
	return;
	
}
void kuaipai(double* a,int l,int r)
{
	int i=l,j=l;
	double x=a[r];
	double y=0;
	if(l>=r)
		return;
	
	for(i=l;i<=r-1;i++)
	{
		if(a[i]>x)
		{
			y=a[i];
			a[i]=a[j];
			a[j]=y;
			j++;
		}
	}
	y=a[j];
	a[j]=a[r];
	a[r]=y;
	
	kuaipai(a,l,j-1);
	kuaipai(a,j+1,r);
	return;
}


