#include<stdio.h>
#define PI 3.14159265358979323

int main()
{
	int n=0;
	double area=0.0; 
	scanf("%d",&n);
	area=PI*n*n;
	printf("%0.7lf",area);
	
	return 0;
}

//
//����һ��ǿ������ת���У���(int)(a)��������int(a) 
//������� ֮ǰд��һ��(int)(PI*n*n)*1e8,�������ֶ���int��ʱ�����ܵ������ 
