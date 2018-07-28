#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int maxx=99999;
char map[20][20];
int vis[20][20];
int go[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};
int n,m;
struct node
{
    int x,y;
    int cnt;
};
vector<node>v;
int bfs(node a,node b)
{
    mem(vis,0);
    queue<node>q;
    vis[a.x][a.y]=vis[b.x][b.y]=1;
    a.cnt=0,b.cnt=0;
    q.push(a),q.push(b);
    int ans=maxx;
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        ans=a.cnt;
        for(int i=0; i<4; i++)
        {
            b.x=a.x+go[i][0];
            b.y=a.y+go[i][1];
            b.cnt=a.cnt+1;
            if(b.x>=0&&b.x<n&&b.y>=0&&b.y<m&&vis[b.x][b.y]==0&&map[b.x][b.y]=='#')
            {
                vis[b.x][b.y]=1;
                q.push(b);
            }
        }
    }
    return ans;
}
int main()
{
    int t,qt=1;
    scanf("%d",&t);
    while(t--)
    {
        v.clear();
        scanf("%d%d",&n,&m);
        getchar();
        for(int i=0; i<n; i++)
        {
            scanf("%s",map[i]);
            for(int j=0; j<m; j++)
            {
                if(map[i][j]=='#')
                    v.push_back((node){i,j,0});
            }
        }
        int ans=maxx;
        for(int i=0; i<v.size(); i++)
        {
            for(int j=i; j<v.size(); j++)
            {
                int tmp=bfs(v[i],v[j]);
                bool ok=true;
                for(int k=0; k<n; k++)
                {
                    for(int f=0; f<m; f++)
                    {
                        if(vis[k][f]==0&&map[k][f]=='#')
                        {
                            ok=false;
                            break;
                        }
                    }
                    if(ok==false)
                        break;
                }
                if(ok)ans=min(ans,tmp);
            }
        }
        printf("Case %d: ",qt++);
        if(ans==maxx)
            printf("-1\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
