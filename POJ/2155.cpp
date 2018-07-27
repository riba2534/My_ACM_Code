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
const int N=1030+7;
int n;
int c[N][N];
inline int lowbit(int t)
{
    return t&(-t);
}
void update(int x,int y,int v)
{
    for (int i=x; i<=n; i+=lowbit(i))
        for (int j=y; j<=n; j+=lowbit(j))
            c[i][j]+=v;
}
int query(int x,int y)
{
    int s=0;
    for (int i=x; i>0; i-=lowbit(i))
        for (int j=y; j>0; j-=lowbit(j))
            s+=c[i][j];
    return s;
}
int sum(int x1,int y1,int x2,int y2)
{
    x1--,y1--;
    return query(x2,y2)-query(x2,y1)-query(x1,y2)+query(x1,y1);
}
int main()
{
    int m,x1,y1,x2,y2,k,x,y;
    char s[2];
    int t;
    scanf("%d",&t);
    while(t--)
    {
        mem(c,0);
        scanf("%d%d",&n,&m);
        while(m--)
        {
            scanf("%s",s);
            if(s[0]=='C')
            {
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                update(x2+1,y2+1,1);
                update(x1,y1,1);
                update(x1,y2+1,1);
                update(x2+1,y1,1);
            }
            else if(s[0]=='Q')
            {
                scanf("%d%d",&x,&y);
                printf("%d\n",query(x,y)%2);
            }
        }
        puts("");
    }
    return 0;
}
