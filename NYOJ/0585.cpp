 
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
    int t,n,x;
    scanf("%d",&t);
    while(t--)
    {
        int ans=0;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&x);
            ans^=x;
        }
        if(ans==0)puts("HRDV");
        else puts("PIAOYI");
    }
    return 0;
}
        