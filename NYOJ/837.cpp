 
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <sstream>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0; i<=n; i++)
        {
            int s=floor(i*((sqrt(5.0)+1)/2));
            printf("(%d,%d)",s,s+i);
        }
        puts("");
    }
    return 0;
}
        