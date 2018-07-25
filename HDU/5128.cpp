#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N 50
#define ll long long
using namespace std;
struct point//坐标点
{
    int x,y;
} g[N];
struct ju//矩形
{
    point a,b;//矩形a一定在矩形b的右下方
    int area;
} zz[N*N];
int map[300][300];
bool cmp(point a,point b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int judge(int i,int j)
{
    //确定是都相离
    if(zz[i].a.x>zz[j].b.x) return 1;
    if(zz[i].a.y>zz[j].b.y) return 1;
    if(zz[j].a.x>zz[i].b.x) return 1;
    if(zz[j].a.y>zz[i].b.y) return 1;

    //是否有i包含j
    if(zz[i].a.x<zz[j].a.x&&zz[i].a.y<zz[j].a.y&&zz[i].b.x>zz[j].b.x&&zz[i].b.y>zz[j].b.y)
        return 2;
    else
        return 0;
}
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        mem(map,0);
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&g[i].x,&g[i].y);
            map[g[i].x][g[i].y]=1;
        }
        sort(g,g+n,cmp);
        int len=0;
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
            {
                if(g[j].x>g[i].x&&g[j].y>g[i].y)//判断两个点能不能构成矩形
                {
                    if(map[g[i].x][g[j].y]&&map[g[j].x][g[i].y])//判断这两个点的组合是否存在
                    {
                        zz[len].a.x=g[i].x;
                        zz[len].a.y=g[i].y;
                        zz[len].b.x=g[j].x;
                        zz[len].b.y=g[j].y;
                        zz[len++].area=(g[j].x-g[i].x)*(g[j].y-g[i].y);
                    }
                }
            }
//        printf("len=%d\n",len);
//
//        for(int i=0;i<len;i++)
//        {
//            printf("   zz[%d]=%d\n",i,zz[i].area);
//        }
        int maxx=0;
        for(int i=0; i<len; i++)
            for(int j=i+1; j<len; j++)
            {
                if(judge(i,j)==1)
                    maxx=max(maxx,zz[i].area+zz[j].area);
                else if(judge(i,j)==2)
                    maxx=max(maxx,zz[i].area);
            }
        if(maxx)
            printf("%d\n",maxx);
        else
            puts("imp");
    }
    return 0;
}
