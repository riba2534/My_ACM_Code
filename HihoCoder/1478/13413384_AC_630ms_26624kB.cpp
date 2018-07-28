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
int e[N][N],dis[N][N];
int go[4][2]= {1,0,-1,0,0,1,0,-1};
void bfs()
{
    queue<pir> q;
    mem(dis,-1);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(e[i][j]==0)
            {
                dis[i][j]=0;
                q.push(make_pair(i,j));
            }
        }
    }
    while(!q.empty())
    {
        pir now=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int xx=now.first+go[i][0];
            int yy=now.second+go[i][1];
            if(xx>=0&&xx<n&&yy>=0&&yy<m&&dis[xx][yy]==-1)
            {
                dis[xx][yy]=dis[now.first][now.second]+1;
                q.push(make_pair(xx,yy));
            }
        }

    }

}
int main()
{
    string s;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>s;
        for(int j=0; j<m; j++)
        {
            e[i][j]=s[j]-'0';
        }
    }
    bfs();
    for(int i=0; i<n; i++)
    {
        printf("%d",dis[i][0]);
        for(int j=1; j<m; j++)
            printf(" %d",dis[i][j]);
        printf("\n");
    }


    return 0;
}
