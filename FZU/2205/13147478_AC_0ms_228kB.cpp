#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
const int N=100+10;

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",(n/2)*(n-n/2));
    }
    return 0;
}
