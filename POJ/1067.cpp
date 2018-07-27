#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        if(n>m)swap(n,m);
        int k=floor((m-n)*((sqrt(5.0)+1)/2));
        printf("%d\n",n==k?0:1);
    }
    return 0;
}
