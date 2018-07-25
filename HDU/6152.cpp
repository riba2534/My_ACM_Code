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
#define mod 1000007
#define ll long long
using namespace std;
const int N=3001;
bool vis[N][N];
int main()
{
    int t,n,x;
    scanf("%d",&t);
    while(t--)
    {
        mem(vis,0);
        int s1=0,s2=0;
        scanf("%d",&n);
        for(int i=1; i<n; i++)
            for(int j=i+1; j<=n; j++)
            {
                scanf("%d",&x);
                vis[i][j]=vis[j][i]=x;
            }
        if(n>=6)
            puts("Bad Team!");
        else if(n<=2)
            puts("Great Team!");
        else
        {
            int flag=0;
            for(int i = 1; i <= n; i++)
                for(int j = i + 1; j <= n; j++)
                    for(int k = j + 1; k <= n; k++)
                    {
                        int sum = vis[i][j] + vis[j][k] + vis[i][k];
                        if(sum == 0 || sum == 3)
                            flag=1;
                    }
            if(flag)puts("Bad Team!");
            else puts("Great Team!");
        }
    }
    return 0;
}
