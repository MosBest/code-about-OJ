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
//问题一：c语言中求幂的方法，在 #iinclude<math.h> 头文件里，用pow(a,b)可得到a^b，返回值为double
//问题二：c[i] 在处理字符'A'~'F'和处理数字'0'~'9'，是不一样的。
//问题三：注意用int是装不下8个F的，至少是unsigned int. 
