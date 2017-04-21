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
		
		//将十六进制字符串转化为二进制字符串
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
	c=(char*)malloc(sizeof(char)*(2*len+1));//c用于存放所有的八进制数值 
	for(i=0;i<(len+3-1)/3;i++)//从右向左，每次去十六进制的3个字符 ，总共要去(len+3-1)/3次,(len/3向上取整 ).
	{
		for(j=0;j<3;j++)//从右向左，每次取十六进制的3个字符
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
		for(j=0;j<3;j++)//计算这3个字符代表的10进制值，参考链接的A步 
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
		
		for(j=0;j<4;j++)//将那3个字符转化为4个八进制字符。因为一个16进制表示4个二进制，三个16进制表示12个二进制 ，即4个8进制 
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


//大问题一：关于字符串的输入问题？（scanf 与 gets） (printf与puts)
/*
gets(s)函数与 scanf("%s",&s) 相似，但不完全相同，
使用scanf("%s",&s) 函数输入字符串时存在一个问题，
就是如果输入了空格会认为字符串结束，空格后的字符将作为下一个输入项处理，
但gets()函数将接收输入的整个字符串直到遇到换行为止

字符串的输入与输出  http://c.biancheng.net/cpp/html/3106.html 
http://www.360doc.com/content/13/0731/20/13289166_303888495.shtml
*/ 

//大问题二： 关于scanf缓冲区的问题？消除是一个'\n' 
//方法一：可以加入一行 rewind(stdin); 来消除缓冲区内容
//方法二：可以加入一行 fflush(stdin); 来消除缓冲区内容  //有的编译器好像无效 
//方法三： scanf("%c", &ch);          //方法：消除上一个'\n' 
//方法四： scanf(" %c", &ch);         //(前边添加一个空格)消除上一个'/n'

//问题三：运算数据太大，即使用long long int 也不能够完成。所以先将16进制转化为2进制
//再将2进制转化为8进制  见http://blog.csdn.net/jiluoxingren/article/details/50478759 

//问题四：c语言a/b向上取整. 可写为 (a+b-1)/b
//问题五：遇到错误，想要的输出与实际输出有差别。后来观测发现，c[i*4+j]=(char)((num & 7) +'0'); 
//没有注意&与+的优先级，写成了c[i*4+j]=(char)(num & 7 +'0');
//注意六：数字字符'0'~'9'与字母'A'~'F'的asciia码不是连续的。 
