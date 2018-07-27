#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define inf 1000000
#define mem(a,b) memset(a,b,sizeof(a))

bool isprime(int x)
{
    int m=(int)(sqrt((double)x)+0.5);
    for(int i=2; i<=m; i++)
        if(x%i==0)
            return false;
    return true;
}

int get_digit_sum(int x)
{
    int ans=0;
    while(x)
    {
        ans+=x%10;
        x/=10;
    }
    return ans;
}
int cut(int x)
{
    if(isprime(x))
        return get_digit_sum(x);
    int m=(int)(sqrt((double)x)+0.5);
    for(int i=m; i>=2; i--)
        if(x%i==0)
            return cut(i)+cut(x/i);
}
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        while(n++)
        {
            if(!isprime(n)&&cut(n)==get_digit_sum(n))
                break;
        }
        printf("%d\n",n);
    }
    return 0;
}

