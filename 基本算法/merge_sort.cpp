#include<stdio.h>

void MERGE(int* A,int p,int q,int r)
{
	int n1=q-p+1;
	int n2=r-q;
	int L[n1]={-1}; //最后一位只是标志位，用-1来标志
	int R[n2]={-1}; //最后一位只是标志位，用-1来标志 
	int i=0;
	for(i=0;i<n1;i++)
	{
		L[i]=A[p+i];
	}
	
	for(i=0;i<n2;i++)
	{
		R[i]=A[q+1+i];
	}
	
	i=0;
	int j=0;
	int k=p;
	for(k=p;k<=r && i<n1 && j<n2 ;k++)
	{
		if(L[i]<R[j])
		{
			A[k]=L[i];
			i++;
		}
		else
		{
			A[k]=R[j];
			j++;
		}
	}
	if(i>=n1 && j<n2)//n1用完了 
	{
		for(;k<=r;k++)
		{
			A[k]=R[j];
			j++;
		}
	}
	else if(i<n1 && j>=n2)//n2用完了 
	{
		for(;k<=r;k++)
		{
			A[k]=L[i];
			i++;
		}
	}
}

MERGE_SORT(int* A,int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		MERGE_SORT(A,p,q);
		MERGE_SORT(A,q+1,r);
		MERGE(A,p,q,r);
	}
}
int main(void)
{
	int A[10]={1,3,5,6,9,2,4,5,7,8};
	
	MERGE_SORT(A,0,9);
	for(int i=0;i<10;i++)
	{
		printf("%d ",A[i]);
	}
	return 0;
}
