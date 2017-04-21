//¿ìËÙÅÅĞò 
#include <stdio.h>

int PARTITION(int* A,int p,int r)
{
	int x=A[r];
	int j=p-1;
	int y=-1;
	for(int i=p;i<r;i++)
	{
		if(A[i]<x)
		{
			j=j+1;
			y=A[j];
			A[j]=A[i];
			A[i]=y;
		}
	}
	y=A[j+1];
	A[j+1]=A[r];
	A[r]=y;
	
	return j+1;
}

void QUICKSORT(int* A,int p,int r)
{
	if(p<r)
	{
		int q=PARTITION(A,p,r);
		QUICKSORT(A,p,q-1);
		QUICKSORT(A,q+1,r);
	}
}

int main(void)
{
	int A[5]={1,4,5,3,2};
	
	QUICKSORT(A,0,4);
	
	for(int i=0;i<5;i++)
	{
		printf("%d ",A[i]);
	}
	
	return 0;
}
