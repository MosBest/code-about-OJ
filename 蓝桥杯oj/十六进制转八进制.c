#include<stdio.h> 
#include<string.h>
#include<malloc.h>

char* sixteen2two(char* s,int len);

int main()
{
	int n=0;
	int i=0;
	int j=0;
	int len=0;
	char c[1000000]={'\0'};
	char* s[10]={0};
	char* s_eight[10]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		rewind(stdin);
		gets(c);
		len=strlen(c);
		s[i]=(char *)malloc(sizeof(char)*(len+1));
		for(j=0;j<len+1;j++)
		{
			s[i][j]=c[j];
		}
		
		//��ʮ�������ַ���ת��Ϊ�������ַ���
		//http://blog.csdn.net/jiluoxingren/article/details/50478759
		s_eight[i]=sixteen2two(s[i],len);
	}
	for(i=0;i<n;i++)
	{
		printf("%s\n",s_eight[i]);
	}
	
	return 0;
}

char* sixteen2two(char* s,int len)
{
	char k[3]={0};
	int i=0;
	int j=0;
	int num=0;
	int len_c=0;
	char* c=0;
	char* finally=0;
	c=(char*)malloc(sizeof(char)*(2*len+1));//c���ڴ�����еİ˽�����ֵ 
	for(i=0;i<(len+3-1)/3;i++)//��������ÿ��ȥʮ�����Ƶ�3���ַ� ���ܹ�Ҫȥ(len+3-1)/3��,(len/3����ȡ�� ).
	{
		for(j=0;j<3;j++)//��������ÿ��ȡʮ�����Ƶ�3���ַ�
		{
			if(len-1-j-3*i < 0)
			{
				k[2-j]='0';
			}
			else
			{
				k[2-j]=s[len-1-j-3*i];
			}
			
		}
		/*for(j=0;j<3;j++)
		{
			printf("%c",k[j]);
		}
		printf("\n");*/
		for(j=0;j<3;j++)//������3���ַ������10����ֵ���ο����ӵ�A�� 
		{
			if(k[j]>='0' && k[j]<='9')
			{
				num=num*16+(k[j]-'0');
			}
			else
			{
				num=num*16+(k[j]-'A'+10);
			}
		}
		
		//printf("num:%d\n",num); 
		
		for(j=0;j<4;j++)//����3���ַ�ת��Ϊ4���˽����ַ�����Ϊһ��16���Ʊ�ʾ4�������ƣ�����16���Ʊ�ʾ12�������� ����4��8���� 
		{
			//printf("%c\n",num & 7);
			c[i*4+j]=(char)((num & 7) +'0');
			num=num>>3;
			//printf("%c\n",c[i*4+j]);
		 }
		
		/*for(j=0;j<4;j++) 
		{
			printf("%c",c[i*4+j]);
		}*/
	}
	c[(i-1)*4+j]='\0';
	for(i=strlen(c)-1;i>=0;i--)
	{
		if(c[i]!='0')
		{
			break;
		}
		c[i]='\0';
	}
	finally=(char*)malloc(sizeof(char)*(strlen(c)+1));
	len_c=strlen(c);
	for(i=0;i<len_c;i++)
	{
		finally[i]=c[len_c-1-i];
	}
	finally[i]='\0';
	//puts(finally);
	return finally; 
}


//������һ�������ַ������������⣿��scanf �� gets�� (printf��puts)
/*
gets(s)������ scanf("%s",&s) ���ƣ�������ȫ��ͬ��
ʹ��scanf("%s",&s) ���������ַ���ʱ����һ�����⣬
������������˿ո����Ϊ�ַ����������ո����ַ�����Ϊ��һ���������
��gets()��������������������ַ���ֱ����������Ϊֹ

�ַ��������������  http://c.biancheng.net/cpp/html/3106.html 
http://www.360doc.com/content/13/0731/20/13289166_303888495.shtml
*/ 

//��������� ����scanf�����������⣿������һ��'\n' 
//����һ�����Լ���һ�� rewind(stdin); ����������������
//�����������Լ���һ�� fflush(stdin); ����������������  //�еı�����������Ч 
//�������� scanf("%c", &ch);          //������������һ��'\n' 
//�����ģ� scanf(" %c", &ch);         //(ǰ�����һ���ո�)������һ��'/n'

//����������������̫�󣬼�ʹ��long long int Ҳ���ܹ���ɡ������Ƚ�16����ת��Ϊ2����
//�ٽ�2����ת��Ϊ8����  ��http://blog.csdn.net/jiluoxingren/article/details/50478759 

//�����ģ�c����a/b����ȡ��. ��дΪ (a+b-1)/b
//�����壺����������Ҫ�������ʵ������в�𡣺����۲ⷢ�֣�c[i*4+j]=(char)((num & 7) +'0'); 
//û��ע��&��+�����ȼ���д����c[i*4+j]=(char)(num & 7 +'0');
//ע�����������ַ�'0'~'9'����ĸ'A'~'F'��asciia�벻�������ġ� 
