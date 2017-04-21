//最大子数组问题，寻找数组A的和最大的非空连续子数组 
//遇到的问题：node* n 是一个指针，所以要给他分配实体 malloc 
#include <stdio.h>
#include <malloc.h>

typedef struct
{
	int low;
	int high;
	int data;
 }node;
 

node FIND_MAX_CROSSING_SUBARRAY(int* A,int low , int mid,int high)
{
	int i=mid;
	int max_low=-1;
	int i_low=-1;
	int sum=0;
	for(i=mid;i>=low;i--)
	{
		sum+=A[i];
		if(sum>max_low)
		{
			max_low=sum;
			i_low=i;
		}
	}
	
	
	int max_high=-1;
	int i_high=-1;
	sum=0;
	for(i=mid;i<=high;i++)
	{
		sum+=A[i];
		if(sum>max_high)
		{
			max_high=sum;
			i_high=i;
		}
	}	
	
	node no;
	no.data=max_high+max_low;
	no.high=i_high;
	no.low=i_low;
	
	return no; 
} 

node* FIND_MAXIMUM_SUBARRAY(int* A,int low ,  int high)
{
	node* n;
	n=(node* )malloc(sizeof(node)*1);
	if(low==high) 
	{
		
		//printf("%d",A[0]);
		n->data=A[low];
		n->high=high;
		n->low=low;
		return n;
	}
	int mid=(high+low)/2;
	node* left=FIND_MAXIMUM_SUBARRAY(A,low,mid);
	node* right=FIND_MAXIMUM_SUBARRAY(A,mid+1,high);
	node mide=FIND_MAX_CROSSING_SUBARRAY(A,low ,mid, high);
	
	if(left->data>=right->data)
	{
		n->data=left->data;
		n->high=left->high;
		n->low=left->low;
	}
	else if(right->data>=mide.data)
	{
		n->data=right->data;
		n->high=right->high;
		n->low=right->low;
	}
	else
	{
		n->data=mide.data;
		n->high=mide.high;
		n->low=mide.low;
	}
	
	return n;
}

int main(void)
{
	int A[10]={1,3,6,2,8,-5,-6,7,3,5};
	
	node* n =FIND_MAXIMUM_SUBARRAY(A,0,9);
	printf("low:%d  high:%d  sum:%d\n",n->low,n->high,n->data);
	return 0;
}
