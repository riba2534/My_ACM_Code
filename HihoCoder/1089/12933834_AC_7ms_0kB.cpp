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
typedef pair<int,int> pir;
const int N=1e2+10;
const int M=1e6+10;
int n,m;
int e[N][N];
int main()
{
    int u,v,w;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)for(int j=1; j<=n; j++)
            e[i][j]=i==j?0:inf;
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        if(w<e[u][v])
            e[u][v]=e[v][u]=w;
    }
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(e[i][k]+e[k][j]<e[i][j])
                    e[i][j]=e[i][k]+e[k][j];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            printf("%d ",e[i][j]);
        puts("");
    }
    return 0;
}
