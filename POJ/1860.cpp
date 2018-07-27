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
#define N 100+20
#define M 100000+20
#define inf 0x3f3f3f3f
using namespace std;
int n,m,s;
double v,map[N]= {0},g1[N][N]= {0},g2[N][N]= {0};
int floyd()
{
    double dis[N];
    for(int i=1; i<=n; i++)
        dis[i]=map[i];
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if((map[i]-g2[i][j])*g1[i][j]>map[j])
                    map[j]=(map[i]-g2[i][j])*g1[i][j];
    for(int i=1; i<=n; i++)
        if(dis[i]<map[i])
            return 1;
    return 0;
}
int main()
{

    while(cin>>n>>m>>s>>v)
    {
        for(int i=1; i<=m; i++)
        {
            int a,b;
            double h_ab,m_ab,h_ba,m_ba;
            cin>>a>>b>>h_ab>>m_ab>>h_ba>>m_ba;//h_ab代表汇率从a->b,m_ab表示佣金从a->b
            g1[a][b]=h_ab,g2[a][b]=m_ab;
            g1[b][a]=h_ba,g2[b][a]=m_ba;
        }
        map[s]=v;
        floyd();
        if(floyd())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
