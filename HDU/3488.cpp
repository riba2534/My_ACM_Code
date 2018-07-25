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
using namespace std;
const int N=200+20;
int nx,ny;//两边的点数
int e[N][N];
int match[N],cx[N],cy[N];
int slack[N];
bool visx[N],visy[N];
bool dfs(int x)
{
    visx[x]=true;
    for(int y=0; y<ny; y++)
    {
        if(visy[y])continue;
        int tmp=cx[x]+cy[y]-e[x][y];
        if(tmp==0)
        {
            visy[y]=true;
            if(match[y]==-1||dfs(match[y]))
            {
                match[y]=x;
                return true;
            }
        }
        else if(slack[y]>tmp)
            slack[y]=tmp;
    }
    return false;
}
int KM()
{
    mem(match,-1);
    mem(cy,0);
    for(int i=0; i<nx; i++)
    {
        cx[i]=-inf;
        for(int j=0; j<ny; j++)
            if(e[i][j]>cx[i])
                cx[i]=e[i][j];
    }
    for(int x=0; x<nx; x++)
    {
        mem(slack,inf);
        while(true)
        {
            mem(visx,false);
            mem(visy,false);
            if(dfs(x))break;
            //不存在的时候就要开始加上边
            int d=inf;
            for(int i=0; i<ny; i++)
                if(!visy[i]&&d>slack[i])
                    d=slack[i];//找到最小的d
            for(int i=0; i<nx; i++)
                if(visx[i])
                    cx[i]-=d;
            for(int i=0; i<ny; i++)
            {
                if(visy[i]) cy[i]+=d;
                else slack[i]-=d;
            }
        }
    }
    int res=0;
    for(int i=0; i<ny; i++)
        if(match[i]!=-1)
            res+=e[match[i]][i];
    return res;
}
int main()
{
    int n,m,t,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        mem(e,-inf);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            e[a-1][b-1]=max(e[a-1][b-1],-c);
        }
        nx=ny=n;
        printf("%d\n",-KM());
    }
    return 0;
}
