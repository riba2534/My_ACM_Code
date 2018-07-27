#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define inf 1000000
#define mem(a,b) memset(a,b,sizeof(a))
const int N=1000+7;
struct node
{
    int num,id;
} ans1[N],ans2[N];


int vis[N][N];
bool cmp(node a,node b)
{
    return a.num>b.num;
}
bool cmp2(node a,node b)
{
    return a.id<b.id;
}
int main()
{
    int m,n,k,l,d,x1,y1,x2,y2;
    scanf("%d%d%d%d%d",&m,&n,&k,&l,&d);
    for(int i=1; i<=d; i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1==x2)//横排
        {
            if(y1>y2) swap(y1,y2);
            if(vis[x1][y1]==2)
                vis[x1][y1]=3;
            else
                vis[x1][y1]=1;
        }
        else if(y1==y2)//竖排
        {
            if(x1>x2) swap(x1,x2);
            if(vis[x1][y1]==1)
                vis[x1][y1]=3;
            else
                vis[x1][y1]=2;
        }
    }
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(vis[i][j]==1)
            {
                ans2[j].num++;
                ans2[j].id=j;
            }
            else if(vis[i][j]==2)
            {
                ans1[i].num++;
                ans1[i].id=i;
            }
            else if(vis[i][j]==3)
            {
                ans2[j].num++;
                ans2[j].id=j;
                ans1[i].num++;
                ans1[i].id=i;
            }
        }
    }
    sort(ans1+1,ans1+m+1,cmp);
    sort(ans2+1,ans2+n+1,cmp);
    sort(ans1+1,ans1+k+1,cmp2);
    sort(ans2+1,ans2+l+1,cmp2);
    for(int i=1; i<k; i++)
        printf("%d ",ans1[i].id);
    printf("%d\n",ans1[k].id);
    for(int i=1; i<l; i++)
        printf("%d ",ans2[i].id);
    printf("%d\n",ans2[l].id);
    return 0;
}
