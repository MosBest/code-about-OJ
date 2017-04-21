#include <iostream>


#define SIZE 7
using namespace std;

int* Big(int*a,int size1,int* b, int size2)
{
    int i=0,j=0,k=0;
    int max_size=size1*size2;
    int* c=new int[max_size];

    for(i=0;i<max_size;i++)
    {
        c[i]=0;
        cout<<c[i];
    }
    cout<<endl;
    for(i=0;i<size1;i++)
    {
        k=i;
        for(j=0;j<size2;j++)
        {
           c[k]=c[k]+a[i]*b[j];
           k++;
        }
    }

    for(i=0;i<max_size;i++)
    {
        if(c[i]>=10)
        {
            c[i+1]=c[i+1]+c[i]/10;

            c[i]=c[i]%10;
        }
    }

    return c;

}


int main()
{
    int i=0;
    int* c=NULL;
    int a[SIZE]={1,2,3,4,5,6,7};

    int b[SIZE]={7,6,5,4,3,2,1};

    c=Big(a,SIZE,b,SIZE);

    for(i=SIZE*SIZE-1;i>=0;i--)
    {
        cout<<c[i];
    }

    return 0;
}
