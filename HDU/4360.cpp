#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define N 2222
typedef long long LL;
#define inf (1ll)<<61
typedef pair<int,int>Pair;
struct Node
{
    int v,w,id;
};
LL dis[N][4];
int num[N][4];
bool vis[N][4];
int n,m;
char str[4];
vector<Node>map[N];

int Change(char ch)
{
    if(ch=='L')return 0;
    else if(ch=='O')return 1;
    else if(ch=='V')return 2;
    else if(ch=='E')return 3;
}

void spfa()
{
    for(int i=0; i<=n; i++)
        for(int j=0; j<4; j++)
            dis[i][j]=inf;
    memset(vis,false,sizeof(vis));
    memset(num,0,sizeof(num));
    dis[1][3]=0;
    vis[1][3]=true;
    queue<Pair>Q;
    Q.push(make_pair(1,3));
    while(!Q.empty())
    {
        Pair pp=Q.front();
        Q.pop();
        int u=pp.first;
        int id=pp.second;
        vis[u][id]=false;
        //   printf("%d\n",id);
        for(int i=0; i<map[u].size(); i++)
        {
            int v=map[u][i].v;
            int w=map[u][i].w;
            int nid=map[u][i].id;
            if((id+1)%4==nid)
            {
                if(dis[v][nid]>dis[u][id]+w)
                {
                    dis[v][nid]=dis[u][id]+w;
                    num[v][nid]=num[u][id];
                    if(nid==3)num[v][nid]++;
                    if(!vis[v][nid])
                    {
                        vis[v][nid]=true;
                        Q.push(make_pair(v,nid));
                    }
                }
                else if(dis[v][nid]==dis[u][id]+w&&num[v][nid]<=num[u][id])
                {
                    num[v][nid]=num[u][id];
                    if(nid==3)num[v][nid]++;
                    if(!vis[v][nid])
                    {
                        vis[v][nid]=true;
                        Q.push(make_pair(v,nid));
                    }
                }
            }
        }
        //льеп
        if(n==1&&num[1][3]==0&&dis[1][3]==0)
            dis[1][3]=inf;
    }
}


int main()
{
    int _case,t=1,u,v,w,tmp;
    scanf("%d",&_case);
    while(_case--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)map[i].clear();
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d%s",&u,&v,&w,str);
            tmp=Change(str[0]);
            Node p1,p2;
            p1.v=v,p2.v=u;
            p1.w=p2.w=w;
            p1.id=p2.id=tmp;
            map[u].push_back(p1);
            map[v].push_back(p2);
        }
        spfa();
        if(dis[n][3]==inf||num[n][3]==0)
        {
            printf("Case %d: Binbin you disappoint Sangsang again, damn it!\n",t++);
        }
        else
            printf("Case %d: Cute Sangsang, Binbin will come with a donkey after travelling %I64d meters and finding %d LOVE strings at last.\n",t++,dis[n][3],num[n][3]);
    }
    return 0;
}