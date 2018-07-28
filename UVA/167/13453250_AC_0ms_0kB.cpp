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
#define pir pair<int,int>
typedef long long ll;
const int N=20;
int num[N][N];
int c[N];
int tot,ans;
void dfs(int cur,int n)
{
    if(cur==n)
    {
        tot++;
        int sum=0;
        for(int i=0; i<8; i++)
        {
            int x=i;
            int y=c[i];
            sum+=num[x][y];
        }
        ans=max(ans,sum);
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            int ok=1;
            c[cur]=i;
            for(int j=0; j<cur; j++)
            {
                if(c[cur]==c[j]||cur-c[cur]==j-c[j]||cur+c[cur]==j+c[j])
                {
                    ok=0;
                    break;
                }
            }
            if(ok)
                dfs(cur+1,n);
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        tot=0,ans=0;
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                cin>>num[i][j];
            }
        }
        dfs(0,8);
        printf("%5d\n",ans);
      
    }
    return 0;
}
