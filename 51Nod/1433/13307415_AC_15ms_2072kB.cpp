#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
typedef long long ll;
const int N=10000000+5;
int n;
int main()
{
    scanf("%d",&n);
    int x,sum1=0,sum2=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);
        if(x==0) sum1++;
        if(x==5) sum2++;
    }
    if(sum1>=1&&sum2>=9)
    {
        for(int i=1; i<=(sum2/9)*9; i++)
            printf("5");
        for(int i=1; i<=sum1; i++)
            printf("0");
        puts("");
    }
    else
    {
        if(sum1!=0)
            puts("0");
        else
            puts("-1");
    }
    return 0;
}
