//#include <cstdio>
//#include <cstring>
//#include <cctype>
//#include <string>
//#include <set>
//#include <iostream>
//#include <stack>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#define mem(a,b) memset(a,b,sizeof(a))
//#define inf 0x3f3f3f3f
//#define mod 10000007
//#define debug() puts("what the fuck!!!")
//#define N 1001000
//#define M 1000000
//#define ll long long
//using namespace std;
//int n,m,ans,t,sx,sy,ex,ey;
//char map[25][25];
//int vis[25][25][(1<<10)+20];//用二进制位来记录状态
//int go[4][2]= {0,1,0,-1,1,0,-1,0};
//struct node
//{
//    int x,y,st;
//};
//int bfs(int x,int y)
//{
//    node now,to;
//    now.x=x,now.y=y,now.st=0;
//    vis[x][y][0]=1;
//    queue<node>q;
//    while(!q.empty())
//    {
//        now=q.front();
//        q.pop();
//        if(now.x==ex&&now.y==ey)
//            return now.st;
//        for(int i=0; i<4; i++)
//        {
//            to.x=now.x+go[i][0];
//            to.y=now.y+go[i][1];
//            to.st=now.st;
//            if(to.x>=0&&to.x<=n&&to.y>=0&&to.y<=m&&map[to.x][to.y]!='*'&&!vis[to.x][to.y][to.st])
//            {
//                if(map[to.x][to.y]>='a'&&map[to.x][to.y]<='j')
//                {
//                    to.st=to.st|(1<<(map[to.x][to.y]-96));
//                }
//                if(map[to.x][to.y]>='A'&&map[to.x][to.y]<='J')
//                {
//
//                }
//
//            }
//
//
//
//
//
//        }
//
//    }
//
//
//    return -1;
//}
//int main()
//{
//   // printf("%d",'b'-96);
//    while(~scanf("%d%d%d",&n,&m,&t))
//    {
//        for(int i=0; i<n; i++)
//        {
//            scanf("%s",map[i]);
//            for(int j=0; j<m; j++)
//            {
//                if(map[i][j]=='@')//找出起点的坐标
//                {
//                    sx=i;
//                    sy=j;
//                }
//                if(map[i][j]=='^')
//                {
//                    ex=i;
//                    ey=j;
//                }
//            }
//        }
//        ans=bfs(sx,sy);
//        if(ans>=t)
//            puts("-1");
//        else
//            printf("%d\n",ans);
//    }
//    return 0;
//}
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=20+10;
char map[maxn][maxn];
int n,m,t;
bool vis[maxn][maxn][(1<<10)+10];
int dx[]= {-1,1,0,0};
int dy[]= {0,0,-1,1};
struct Point
{
    int x,y,step;
    int key;
};
queue<Point>Q;
Point st;
bool check(int x,int y)
{
    if(x>=1&&x<=n&&y>=1&&y<=m&&map[x][y]!='*')
        return true;
    return false;
}
int bfs()
{
    while(!Q.empty())  Q.pop();
    memset(vis,false,sizeof(vis));
    vis[st.x][st.y][st.key]=true;
    st.key=st.step=0;
    Q.push(st);
    Point cur,nex;
    while(!Q.empty())
    {
        cur=Q.front();
        Q.pop();
        if(map[cur.x][cur.y]=='^')
            return cur.step;
        for(int i=0; i<4; i++)
        {
            nex.x=cur.x+dx[i];
            nex.y=cur.y+dy[i];
            nex.key=cur.key;
            if(check(nex.x,nex.y))
            {
                nex.step=cur.step+1;
                if(nex.step>=t)
                    continue;
                else if(map[nex.x][nex.y]>='A'&&map[nex.x][nex.y]<='Z')
                {
                    int temp=map[nex.x][nex.y]-'A';
                    int nk=cur.key&1<<temp;
                    if(nk&&!vis[nex.x][nex.y][nex.key])
                    {
                        vis[nex.x][nex.y][nex.key]=true;
                        Q.push(nex);
                    }
                }
                else if(map[nex.x][nex.y]>='a'&&map[nex.x][nex.y]<='z')
                {
                    int temp=map[nex.x][nex.y]-'a';
                    nex.key=cur.key|1<<temp;
                    if(!vis[nex.x][nex.y][nex.key])
                    {
                        vis[nex.x][nex.y][nex.key]=true;
                        Q.push(nex);
                    }
                }
                else
                {
                    if(!vis[nex.x][nex.y][nex.key])
                    {
                        vis[nex.x][nex.y][nex.key]=true;
                        Q.push(nex);
                    }
                }
            }
        }
    }
    return -1;
}
inline void read_graph()
{
    char str[maxn];
    for(int i=1; i<=n; i++)
    {
        scanf("%s",str+1);
        for(int j=1; j<=m; j++)
        {
            if(str[j]=='@')
            {
                st.x=i;
                st.y=j;
                map[i][j]=str[j];
            }
            else  map[i][j]=str[j];
        }
    }
}
    int main()
    {
        while(~scanf("%d%d%d",&n,&m,&t))
        {
            read_graph();
            int ans=bfs();
            printf("%d\n",ans);
        }
        return 0;
    }
