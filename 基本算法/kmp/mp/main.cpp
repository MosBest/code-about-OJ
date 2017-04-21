#include <iostream>
#include <string.h>
#define M 6
using namespace std;


void calcF(const char* s,int* F,int m)
{
    int i=0;
    int j=-1;

    F[0]=-1;

    for(;i<m;)
    {
        while(j>-1&&s[j]!=s[i])
            j=F[j];

        i++;
        j++;
        F[i]=j;
    }
}

int main()
{
    string target="hello world my name is dinglei";
    string pattern="world";
    int F[M];
    int i=0,j=0;

    for(i=0;i<M;i++)
    {
        F[i]=0;
    }


    const char* t=target.c_str();
    const char* p=pattern.c_str();
    calcF(p,F,pattern.length());
    for(i=0,j=0;i<target.length();)
    {

        while(j>-1 &&p[j]!=t[i])
            {
                j=F[j];
            }

        i++;
        j++;
        if(j>=pattern.length())
            cout <<i<<endl;

    }

    cout << "Hello world!" << endl;
    return 0;
}

