#include<stdio.h> 

void insert_sort(int* d,int len)
{
	 int data[len]={0};
	 data[0]=d[0];
	 int a=-1;
	 int j=0;
	 for(int i=1;i<len;i++)
	 {
	 	a=d[i];
	 	j=i-1;
	 	while(j>=0  && a<=data[j])
	 	{
	 		
	 			data[j+1]=data[j];
				 j--;
		}
		if(j<0)
		{
			data[0]=a; 
		}
		else
		{
			data[j+1]=a;
		}
	 	
	 }
	 
	 for(int i=0;i<len;i++)
	 {
	 	printf("%d ",data[i]);
	 }
}

int main(void)
{
	int data[10]={-1};
	printf("随机的输入10数字：");
	int i=0;
	for(i=0;i<10;i++)
	{
		scanf("%d",data+i);
	}
	
	insert_sort(data,10);
	return 0;
	
}
