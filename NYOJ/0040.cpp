 
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int q;
    scanf("%d",&q);
    int a,b;
    while(q--)
    {
        scanf("%d %d",&a,&b);
        int p=__gcd(a,b);
        int q=(a*b)/p;
        printf("%d %d\n",p,q);
    }
    return 0;
}        