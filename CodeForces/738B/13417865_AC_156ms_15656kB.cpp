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
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;
const int N=1000+20;
int n,m;
int e[N][N],r[N][N],c[N][N];
int get_num(int x,int y)
{
    int sum=0;
    if(r[x][m]>r[x][y])
        sum++;
    if(r[x][y]>0)
        sum++;
    if(c[x][y]>0)
        sum++;
    if(c[n][y]>c[x][y])
        sum++;
    return sum;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%d",&e[i][j]);
            r[i][j]=r[i][j-1]+e[i][j];
            c[i][j]=c[i-1][j]+e[i][j];
        }
    }
    int ans=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(!e[i][j])
                ans+=get_num(i,j);
        }
    }
    printf("%d\n",ans);
    return 0;
}
