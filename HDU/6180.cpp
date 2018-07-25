//#include <cstdio>
//#include <cstring>
//#include <cctype>
//#include <string>
//#include <set>
//#include <iostream>
//#include <stack>
//#include <cmath>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#define mem(a,b) memset(a,b,sizeof(a))
//#define mod 1000007
//#define M 12357
//#define ll long long
//using namespace std;
//const ll N=100000+100;
//const ll inf=1e18;
//ll n,m,a,b,c,t;
//struct SPFA
//{
//  ll first[N*4],len,vis[N],dis[N],inq[N],pre[N];
//  vector<ll>path;
//  void init()
//  {
//      mem(first,-1);
//      mem(vis,0);
//      mem(dis,0);
//      mem(inq,0);//记录当前点是不是最短路径上的点
//      len=1;
//      path.clear();
//      pre[1]=-1;
//  }
//  struct node
//  {
//      ll u,v,w,next;
//  } G[N*4];
//  void add_edge(ll u,ll v,ll w)
//  {
//      G[len].v=v,G[len].w=w;
//      G[len].next=first[u];
//      first[u]=len++;
//  }
//  void spfa(ll st)
//  {
//      for(ll i=1; i<=n; i++)
//      {
//          dis[i]=inf;
//          vis[i]=0;
//      }
//      dis[st]=0;
//      vis[st]=1;
//      queue<ll>q;
//      q.push(st);
//      while(!q.empty())
//      {
//          st=q.front();
//          q.pop();
//          vis[st]=0;
//          for(ll i=first[st]; i!=-1; i=G[i].next)
//          {
//              ll v=G[i].v,w=G[i].w;
//              if(dis[v]>dis[st]+w)
//              {
//                  pre[v]=st;
//                  dis[v]=dis[st]+w;
//                  if(!vis[v])
//                  {
//                      vis[v]=1;
//                      q.push(v);
//                  }
//              }
//          }
//      }
//  }
//  void print_path(int x)
//  {
//      if(pre[x]!=-1)
//      {
//          print_path(pre[x]);
//          inq[x]=1;
//          path.push_back(x);
//      }
//  }
//} s1,s2;
//
//int main()
//{
//  ll t;
//  scanf("%lld",&t);
//  while(t--)
//  {
//      scanf("%lld%lld",&n,&m);
//      s1.init();
//      s2.init();
//      for(ll i=1; i<=m; i++)
//      {
//          scanf("%lld%lld%lld",&a,&b,&c);
//          s1.add_edge(a,b,c);
//          s1.add_edge(b,a,c);
//          s2.add_edge(a,b,c);
//          s2.add_edge(b,a,c);
//      }
//      s1.spfa(1);
//      s1.print_path(n);
//      s2.spfa(n);
//      ll minn=inf,k=s1.dis[n];
//      for(ll i=2; i<=n-1; i++)
//      {
//          if(s1.dis[i]+s2.dis[i]<=minn)
//          {
//              if(s1.inq[i]&&s1.dis[i]+s2.dis[i]==k)//如果当前用来松弛的点是最短路中出现过的点
//                  continue;
//              minn=s1.dis[i]+s2.dis[i];
//          }
//      }
//      s1.path.push_back(1);//把1号点加入路径
//      ll minc=inf;
//      for(ll i=0; i<s1.path.size(); ++i)
//      {
//          for(ll j=s1.first[s1.path[i]]; ~j; j=s1.G[j].next)//遍历最短路径上的点的出边
//          {
//              ll w=s1.G[j].w;
//              minc=min(minc,w);//找出最小的边
//          }
//      }
//      if(n==2)
//          printf("%lld\n",3*s1.dis[n]);
//      else
//      {
//          if(minn==inf)
//              printf("%lld\n",s1.dis[n]+2*minc);
//          else
//              printf("%lld\n",min(minn,s1.dis[n]+2*minc));
//      }
//  }
//  return 0;
//}

#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
typedef long long int ll;
const int mx = 1e5+5;
struct node
{
    int s,e;
} a[mx];
bool cmp(node a,node b)
{
    return a.s<b.s;
}
multiset<int>st;
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        st.clear();
        for(int i = 0; i < n; i++)
            scanf("%d%d",&a[i].s,&a[i].e);
        sort(a,a+n,cmp);
        ll ans = 0;
        for(int i = 0; i < n; i++)
        {
            multiset<int>::iterator it;
        it = st.upper_bound(a[i].s);
            if(it==st.begin())
            {
                ans += a[i].e-a[i].s;
                st.insert(a[i].e);
            }
            else
            {
                it--;
                ans += a[i].e-*it;
                st.erase(it);
                st.insert(a[i].e);
            }
        }
        printf("%d %I64d\n",st.size(),ans);
    }
    return 0;
}
