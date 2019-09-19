//dev-c++中，输出a ，如果a是double,但是你的printf是 %d ，那么回出错误，最终输出0 
/*#include<stdio.h>

int main()
{
	long long int a=0;
	int b=0;
	int i=0;
	for(i=1;i<=100;i++)
	{
		b=b+i;
		a=a+b;		
	}
	printf("%d",a);
	return 0;
}
*/
/*
#include<stdio.h>

int main()
{
	int i=0,n=0;
	for(i=1;i<=150;i++)
	{
		for(n=0;n<=200;n++)
		{
			if(2*i*n+n*n-n==236)
			printf("i %d n %d\n",i,n);
		}
	}
	return 0;
}
*/

#include<stdio.h>

int main()
{
	int A=0,B=0,C=0,D=0,E=0,F=0,G=0,H=0,I=0;
	long long int a=0,b=0;
	
		for(A=1;A<=9;A++)
		{
			
			for(B=1;B<=9;B++)
			{
				if(A==B) continue;
				for(C=1;C<=9;C++)
				{
					if(C==B || C==A) continue;
					for(D=1;D<=9;D++)
					{
						if(D==B || D==A || D==C) continue;
						for(E=1;E<=9;E++)
						{
							if(E==B || E==A || E==C || E==D) continue;
							for(F=1;F<=9;F++)
							{
								if(F==B || F==A || F==C || F==D || F==E  ) continue;
								for(G=1;G<=9;G++)
								{
									if(G==B || G==A || G==C || G==D || G==E || G==F ) continue;
									for(H=1;H<=9;H++)
									{
										if(H==B || H==A || H==C || H==D || H==E || H==F ||H==G ) continue;
										for(I=1;I<=9;I++)
										{
											if(I==B || I==A || I==C || I==D || I==E || I==F || I==H || I==G) continue;
											a=G*100+H*10+I;
											if((A*C*a+B*a+(D*100+E*10+F)*C)%(C*a)==0) 
											{
												if((A*C*a+B*a+(D*100+E*10+F)*C)/(C*a)==10)
												{
													b=b+1;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	
	printf("%I64d",b);
	return 0;
}
/*
#include <stdio.h>  
  
void swap(int a[], int i, int j)  
{  
    int t = a[i];  
    a[i] = a[j];  
    a[j] = t;  
}  
  
int partition(int a[], int p, int r)  
{  
    int i = p;  
    int j = r + 1;  
    int x = a[p];  
    while(1){  
        while(i<r && a[++i]<x);  
        while(a[--j]>x);  
        if(i>=j) break;  
        swap(a,i,j);  
    } 
    
    swap(a,p,j);//填空位置  
    return j;  
}  
  
void quicksort(int a[], int p, int r)  
{  
    if(p<r){  
        int q = partition(a,p,r);  
        quicksort(a,p,q-1);  
        quicksort(a,q+1,r);  
    }  
}  
      
int main()  
{  
    int i;  
    int a[] = {5,13,6,24,2,8,19,27,6,12,1,17};  
    int N = 12;  
      
    quicksort(a, 0, N-1);  
      
    for(i=0; i<N; i++) printf("%d ", a[i]);  
    printf("\n");  
      
    return 0;  
}*/
/*
#include <stdio.h>  
#define N 6  
#define M 5  
#define BUF 1024  
int num=0;
void f(int a[], int k, int m, char b[])  
{  
    int i,j;  
      
    if(k==N){   
        b[M] = 0;  
        if(m==0) {
        	printf("%s\n",b);
        	num++;
        	
		};  
        return;  
    }  
      
    for(i=0; i<=a[k]; i++){  
        for(j=0; j<i; j++) b[M-m+j] = k+'A';  
        f(a,k+1,m-i,b) ;
    }  
}  
int main()  
{     
    int  a[N] = {4,2,2,1,1,3};  
    char b[BUF];  
    f(a,0,M,b); 
		
    return 0;  
} */
/*
#include<stdio.h> 
#include<math.h>
int main()
{
	int a=0,b=0,c=0,d=0;
	int k[5]={0};
	int n=0,m=0;
	int F=0;
	int i=4;
	scanf("%d",&n);
	//for(m=6;m<=5000000;m++)
	//{
	//	n=m;
	for(i=4;i>=1;i--)
	{
		F=(int)(sqrt(n));
	
		n=n-F*F;
		k[i]=F;
	}
	a=k[1];
	b=k[2];
	c=k[3];
	d=k[4];
	
	printf("%d %d %d %d\n",a,b,c,d);
	//}
	return 0;
}
*/
