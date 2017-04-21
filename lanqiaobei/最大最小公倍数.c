#include<stdio.h> 

int main()
{
	long long int n=0;
	long long int a=0;
	int i=0;
	scanf("%I64d",&n);

	if(n==3)
	{
		a=6;
	}
	
	if(n<=2)
	{
		a=n;
	}
	
	if(n%2!=0)
	{
		a=(n-2)*(n-1)*n;
	
	}
	else
	{
		for(i=2;i<=4;i++)//因为i<=4 ,所以只需看N-i 与N,N-1 在 2，3，5上面是否有公约数 
		{
			if(((n-i)%2==0) || ((n-i)%3==0 && (((n-1)%3)==0 || (n%3)==0 )) || (((n-i)%5)==0 && (((n-1)%5)==0 || (n%5)==0 )) ) 
			{
				continue;
			}
			else
			{
				a=(n-i)*(n-1)*n;
				break;
			}
		}
		
		if(a==0)//a==0表明不存在好的i 
		{
			a=(n-1)*(n-2)*(n-3);
		}
	}
	
	printf("%I64d\n",a);

	
	return 0;
	
}
//问题一：解决思路
//知道相邻的两个整数是互斥的。对于1~N，将问题范围两种情况
//1. 当N为奇数时，则N，N-1,N-2.都互斥，那么他们的最小公倍数就是N*(N-1)*(N-2)
//2. 当N为偶数时，则N与N-2有公因数2.那么我们就要考虑 1. 要不要选择N , 2. 要不要选择 N-1
//如果选择N，且选择N-1的话，那么N-2不能选(与N有公约数2). 如果N-3不是3的倍数，那么就选N-3，但是如果N-3是3的倍数，那么就不能选N-3
//                              假设选择 N-a .则为 N*(N-1)*(N-a) 
//如果选择N，但不选择N-1的话，但是N-2依然不能选(与N有公约数2)，那么问题就变成了求N*(N-a)*(N-b)
//							    显然这还没有上面的好
//如果不选择N，那么最好的结果就是 (N-1)*(N-2)*(N-3) .下面我们证明 N*(N-1)*(N-a)与 (N-1)*(N-2)*(N-3)哪个好
//
//如果N*(N-1)*(N-a)>(N-1)*(N-2)*(N-3)   <=>  N*(N-a)>(N-2)*(N-3) <=>  a<5-6/N 
//则如果能够找到一个a(a=0,1,2,3,4),使得 N-a 与 N 和 N-1互斥，那么就有 如果N*(N-1)*(N-a)>(N-1)*(N-2)*(N-3)
//                                   否则 N*(N-1)*(N-a) < (N-1)*(N-2)*(N-3)

//综上所述，若N为奇数，则 N*(N-1)*(N-2) ；若N为偶数，且找到了a（a=2,3,4,(0,1不要)），则N*(N-1)*(N-a)，否则，(N-1)*(N-2)*(N-3) 

//大问题： 用了long long int a，a=95150*95151;还报错  warning: integer overflow in expression(-Woverflow)
//原因， 95150*95151虽然没有超过 a的范围，但是 95150*95151 返回的是int。 
// 所以 ，代码中的 a=N*(N-1)*(N-i)等等都有问题，必须把 N设定为 long long int型，才能够使 N*(N-1)*(N-i)返回值类型是 long long int而不是int. 
//  改正  注意：a=(long long int )(95150*95151); 依然是错误的
/* 
long long int a，
a=95150;
a=a*(a+1) ;

或者
a=((long long int )95150*(long long int )95151);
*/
