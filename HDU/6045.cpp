//#include <cstdio>
//#include <cstring>
//#include <cctype>
//#include <string>
//#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 80000+20
#define ll long long
using namespace std;
char s1[N],s2[N];
int main()
{
    int t,n,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%s%s",&n,&x,&y,s1,s2);
        int cnt=0;
        for(int i=0; i<n; i++)
            if(s1[i]==s2[i])
                cnt++;
        if(x+y<=(n+cnt)&&abs(x-y)<=(n-cnt))
            puts("Not lying");
        else
            puts("Lying");
    }
    return 0;
}

