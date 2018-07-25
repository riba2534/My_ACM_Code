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
//#define inf 0x3f3f3f3f
//#define N 220
//#define ll long long
//using namespace std;
//#define lson l,m,rt<<1
//#define rson m+1,r,rt<<1|1
//struct Seg
//{
//  double l,r,h;
//  int f;
//  Seg() {}
//  Seg(double a,double b,double c,int d):l(a),r(b),h(c),f(d) {}
//  bool operator < (const Seg &cmp) const
//  {
//      return h<cmp.h;
//  }
//} e[N];
//struct node
//{
//  int cnt;
//  double len;
//} t[N<<2];
//double X[N];
//void pushdown(int l,int r,int rt)
//{
//  if(t[rt].cnt)
//      t[rt].len=X[r+1]-X[l];
//  else if(l==r)
//      t[rt].len=0;
//  else
//      t[rt].len=t[rt<<1].len+t[rt<<1|1].len;
//}
//void update(int L,int R,int l,int r,int rt,int val)
//{
//  if(L<=l&&r<=R)
//  {
//      t[rt].cnt+=val;
//      pushdown(l,r,rt);
//      return;
//  }
//  int m=(l+r)>>1;
//  if(L<=m) update(L,R,lson,val);
//  if(R>m) update(L,R,rson,val);
//  pushdown(l,r,rt);
//}
//int main()
//{
//  int n,q=1;
//  double a,b,c,d;
//  while(~scanf("%d",&n)&&n)
//  {
//      mem(t,0);
//      int num=0;
//      for(int i=0; i<n; i++)
//      {
//          scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
//          X[num]=a;
//          e[num++]=Seg(a,c,b,1);
//          X[num]=c;
//          e[num++]=Seg(a,c,d,-1);
//      }
//      sort(X,X+num);
//      sort(e,e+num);
//      int m=unique(X,X+num)-X;
//      double ans=0;
//      for(int i=0; i<num; i++)
//      {
//          int l=lower_bound(X,X+m,e[i].l)-X;
//          int r=lower_bound(X,X+m,e[i].r)-X-1;
//          update(l,r,0,m,1,e[i].f);
//          ans+=t[1].len*(e[i+1].h-e[i].h);
//      }
//      printf("Test case #%d\nTotal explored area: %.2lf\n\n",q++,ans);
//  }
//  return 0;
//}

#include<bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int inf=0x3f3f3f3f;
const int N=2200;
struct edge
{
    double l,r,h;
    int f;
    edge() {}
    edge(double x1,double x2,double y,double op)
    {
        l=x1,r=x2,h=y,f=op;
    }
    bool operator < (const edge&A)const
    {
        return h<A.h;
    }
} e[N];
struct node
{
    int cnt;
    double s,ss;
} t[N<<2];
double X[N];
void pushdown(int rt,int l,int r)
{
    //printf("t[%d].cnt=%d\n",rt,t[rt].cnt);
    if(t[rt].cnt)//全部覆盖
        t[rt].s=X[r+1]-X[l];
    else if(l==r)//为一个点，长度为0
        t[rt].s=0;
    else//既不全部覆盖，也不是点，由两边区间得出
        t[rt].s=t[rt<<1].s+t[rt<<1|1].s;

    if(t[rt].cnt>1)
        t[rt].ss=X[r+1]-X[l];
    else if(l==r)
        t[rt].ss=0;
    else if(t[rt].cnt==1)
        t[rt].ss=t[rt<<1].s+t[rt<<1|1].s;
    /*
    cnt==1代表从le到ri这段（完整的）长度从初始到现在被覆盖了一次，所以在这段区间中被覆盖两次
    的长度等于左右子节点中被覆盖一次的长度之和（根节点的覆盖和子节点的覆盖肯定不在同一段线段上）
    */
    else
        t[rt].ss=t[rt<<1].ss+t[rt<<1|1].ss;
}
void update(int x,int y,int l,int r,int rt,int val)
{
    if(x<=l&&y>=r)
    {
        t[rt].cnt+=val;
        pushdown(rt,l,r);
        return;
    }
    int m=(l+r)>>1;
    if(x<=m)
        update(x,y,l,m,rt<<1,val);
    if(y>m)
        update(x,y,m+1,r,rt<<1|1,val);
    pushdown(rt,l,r);
}
int main()
{
    int n,Caes;
    double x1,x2,y1,y2;
    scanf("%d",&Caes);
    while(Caes--)
    {
        scanf("%d",&n);
        mem(t,0);
        int tot=0;
        for(int i=0; i<n; i++)
        {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            X[tot]=x1;
            e[tot++]=edge(x1,x2,y1,1);
            X[tot]=x2;
            e[tot++]=edge(x1,x2,y2,-1);
        }
        sort(X,X+tot);
        sort(e,e+tot);
        int m=unique(X,X+tot)-X;
        double ans=0;
        for(int i=0; i<tot; i++)
        {
            int x=lower_bound(X,X+m,e[i].l)-X;
            int y=lower_bound(X,X+m,e[i].r)-X-1;
            update(x,y,0,m,1,e[i].f);
            ans+=(e[i+1].h-e[i].h)*t[1].ss;
        }
        printf("%.2f\n",ans);
    }
    return 0;
}
