 
#include <iostream>
#include<algorithm>
#include<string.h>
#include<cstdio>
#define minn -9999999
using namespace std;
const int N=41;
int a[N];
void init()
{
    a[0]=0,a[1]=1;
    for(int i=2; i<=40; i++)
        a[i]=a[i-1]+a[i-2];
}
int main()
{
    init();
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n==1)puts("0");
        else
        printf("%d\n",a[n]);
    }
    return 0;
}
        