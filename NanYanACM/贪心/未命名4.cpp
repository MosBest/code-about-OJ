#include<cstdio>  
#include<algorithm>  
using namespace std;  
struct cxj    
{  
    int a;  //a为长度,b为质量   
    int b;  
    int vis;  
}e[5010];  
int cmp(cxj x,cxj y)  
{  
    if(x.b!=y.b) return x.b<y.b;  
    else return x.a<y.a;  
}  
int main()  
{  
    int  T,n,i,j,t,sum,s;  
    scanf("%d",&T);  
    while(T--)  
    {  
        s=0;  
        scanf("%d",&n);  
        for(i=0; i<n; i++)  
        {  
            scanf("%d %d",&e[i].a,&e[i].b);  
            e[i].vis=1;  
        }   
        sort(e,e+n,cmp);  
        
        for(j=0;j<n;j++)
		{
			//printf("%d  %d  %d\n",e[j].a,e[j].b,e[j].vis);
		}
        
        for(i=0; i<n; i++)  
        {  
            t=e[i].a;  
            if(e[i].vis==0) continue;  
            //printf("%d %d\n",e[i].a,e[i].b);
            for(j=i+1; j<n; j++)  
            {  
                if(e[j].vis&&t<=e[j].a)  
                {  
                    e[j].vis=0;  
            //        printf("%d %d\n",e[j].a,e[j].b);
                    t=e[j].a;  
                }  
            }  
            s++;  //进行多少次循环，就是花了多少分钟   
        }  
        printf("%d\n",s);  
    }  
    return 0;  
}  
