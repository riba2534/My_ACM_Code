#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define N 3
#define M 1000000+10
#define ll long long
using namespace std;
int main()
{
    int a,b;
    while(1)
    {
        cin>>a>>b;
        if(a==0&&b==0)return 0;
        if((a*b)&1)
            puts("no");
        else
            puts("yes");
    }
    return 0;
}
