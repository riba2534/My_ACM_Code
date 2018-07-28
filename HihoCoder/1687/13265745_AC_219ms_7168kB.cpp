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
typedef long long ll;
const int N=1000000+20;
struct point
{
    double x,y;
    int id;
} a[N];
double det(double x1,double y1,double x2,double y2)
{
    return x1*y2-x2*y1;
}
bool cmp(point a,point b)
{
    if(a.x==b.x)
        return a.y<b.y;
    else
        return a.x>b.x;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%lf%lf",&a[i].x,&a[i].y);
        a[i].id=i+1;
    }
    sort(a,a+n,cmp);
    double x1=a[1].x-a[0].x;
    double y1=a[1].y-a[0].y;
    int id=1;
    for(int i=2; i<n; i++)
    {
        double x2=a[i].x-a[0].x;
        double y2=a[i].y-a[0].y;
        if(det(x1,y1,x2,y2)>0)
        {
            id=i;
            x1=x2;
            y1=y2;
        }
    }
    printf("%d %d\n",a[0].id,a[id].id);
    return 0;
}
