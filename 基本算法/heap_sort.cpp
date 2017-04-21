//�������㷨
#include <stdio.h> 

void MAX_HEAPIFY(int* A,int len, int i)
{
	int left_child=2*i+1;//�±�i������ 
	int right_child=2*i+2;//�±�i���Һ���
	
	int xiabiao=i;
	int data=-1;
	
	if(left_child<len && A[left_child]>A[i])
	{
		data=A[left_child];
		xiabiao=left_child;
	}
	else
	{
		data=A[i];
		xiabiao=i;
	}
	if(right_child<len && A[right_child]>A[xiabiao])
	{
		data=A[right_child];
		xiabiao=right_child;
	}
	
	if(xiabiao!=i)
	{
		A[xiabiao]=A[i];
		A[i]=data;
		MAX_HEAPIFY(A,len,xiabiao);
	}
}

void BUILD_MAX_HEAP(int* A,int len)//���� 
{
	int n=len; //�������У�����������������˼�룬����len/2+1�ⲿ�ֶ���Ҷ�ӽڵ㣬���ÿ��� 
	//������ �������Ͻ�������
	for(int i=n-1;i>=0;i--) 
	{
		MAX_HEAPIFY(A,len,i);
	}
}

void HEAPSORT(int* A,int len)
{
	BUILD_MAX_HEAP(A,len);
	int a=0;
	for(int i=0;i<len;i++)
	{
		a=A[0];
		A[0]=A[len-1-i];
		A[len-1-i]=a;
		MAX_HEAPIFY(A,len-1-i,0);
	}

}

int main(void)
{
	int A[16]={1,3,4,7,4,3,6,9,2,3,44,1,2,7,11,65};
	HEAPSORT(A,16);
	printf("\n ");
	for(int i=0;i<16;i++)
	{
		printf("%d ",A[i]);
	}
	return 0;
}
