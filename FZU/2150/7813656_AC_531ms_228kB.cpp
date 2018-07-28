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
};//坐标和步数
vector<node>v;
int bfs(node a,node b)
{
    mem(vis,0);
    queue<node>q;
    vis[a.x][a.y]=vis[b.x][b.y]=1;//走过的标记为1
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
            if(b.x>=0&&b.x<n&&b.y>=0&&b.y<m&&vis[b.x][b.y]==0&&map[b.x][b.y]=='#')//判断是否越界
            {
                vis[b.x][b.y]=1;//标记烧过的
                q.push(b);
            }
        }
    }
    return ans;//返回最短时间
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
                    v.push_back((node){i,j,0});//把每一个草地的坐标存入结构体
            }
        }
        int ans=maxx;//定义一下初始最大量
        for(int i=0; i<v.size(); i++)
        {
            for(int j=i; j<v.size(); j++)//遍历所有的草坪对数
            {
                int tmp=bfs(v[i],v[j]);//搜索出烧完草地的最短时间
                bool ok=true;//用来标记是否烧完
                for(int k=0; k<n; k++)
                {
                    for(int f=0; f<m; f++)
                    {
                        if(vis[k][f]==0&&map[k][f]=='#')//如果遇到有草地还没被烧就把ok标记为false
                        {
                            ok=false;
                            break;
                        }
                    }
                    if(ok==false)
                        break;
                }
                if(ok)ans=min(ans,tmp);//找出最短的时间
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
