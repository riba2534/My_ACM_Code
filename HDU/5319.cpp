#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N (2000+20)
#define M 200010
#define MOD (1000000000+7)
#define inf 0x3f3f3f3f
#define LL long long
using namespace std;
char map[60][60];
int n,m,ans;
void dfs(int i,int j,char k)
{
    if(map[i][j] != k&&map[i][j] != 'G')
        return;

    if(map[i][j]==k)
        map[i][j]='.';

    else if(map[i][j] == 'G')
    {
        if(k == 'R')
            map[i][j] = 'B';
        else
            map[i][j] = 'R';
    }
    if(k == 'R')
        dfs( i + 1, j + 1, k );//'\'这样涂
    else if(k == 'B')
        dfs( i + 1, j - 1, k );//‘/’这样涂
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mem(map,0);
        scanf("%d",&n);
        ans=0;
        for(int i=0; i<n; i++)
        {
            scanf("%s",map[i]);
        }
        m=strlen(map[0]);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(map[i][j]=='R')
                {
                    ans++;
                    dfs(i,j,'R');
                }
                else if(map[i][j]=='B')
                {
                    ans++;
                    dfs(i,j,'B');
                }
                else if(map[i][j]=='G')
                {
                    ans+=2;
                    dfs(i,j,'R');
                    dfs(i,j,'B');
                }
            }
        }

        printf("%d\n",ans);
    }
    return 0;
}
