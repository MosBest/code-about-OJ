#include<stdio.h>
#include<string.h>
#include<math.h> 

int main()
{
	char c[8]={'\0'};
	int i=0;
	int len=0;
	unsigned int fina=0;
	scanf("%s",c);
	len=strlen(c);
	for(i=0;i<len;i++)
	{
		if(c[i]>='A' && c[i]<='F')
		{
			fina+=(c[i]-'A'+10)*pow(16,len-i-1);
		}
		else
		{
			fina+=(c[i]-'0')*pow(16,len-i-1);
		}
	}
	printf("%u",fina);
	return 0;
}
//����һ��c���������ݵķ������� #iinclude<math.h> ͷ�ļ����pow(a,b)�ɵõ�a^b������ֵΪdouble
//�������c[i] �ڴ����ַ�'A'~'F'�ʹ�������'0'~'9'���ǲ�һ���ġ�
//��������ע����int��װ����8��F�ģ�������unsigned int. 
