#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int f[100];
void init()
{
    f[0]=2;
    f[1]=3;
    for(int i=2; i<45; i++)
        f[i]=f[i-1]+f[i-2];
}
int main()
{
    init();
    int n;
    while(scanf("%d",&n)&&n)
    {
        int flag=1;
        for(int i=0; i<45; i++)
            if(f[i]==n)
            {
                flag=0;
                break;
            }
        if(flag)puts("First win");
        else puts("Second win");
    }
    return 0;
}
