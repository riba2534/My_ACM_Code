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
#define N 100100
#define M 1000000+10
#define ll long long
using namespace std;
int n,m,y;
int a[N];
struct node
{
    int x,pos;
    double y;
}q[N];
bool cmp1(node a,node b)
{
    if(a.y==b.y)
        return a.pos<b.pos;
    return a.y>b.y;
}
bool cmp2(node a,node b)
{
    return a.pos<b.pos;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&y);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        double cc=m*1.0/y;
        double temp;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            q[i].pos=i;
            temp=a[i]*cc;//另他们详见的绝对值=0，然后推出ki=xi*(m/y)
            q[i].x=(int)temp;//取整数部分
            q[i].y=temp-q[i].x;//取小数部分
            sum+=q[i].x;//把整数部分的值加起来
        }
        sum=m-sum;//整数部分和m的值相差的位数
        sort(q+1,q+n+1,cmp1);//小数部分从大到小排序
        for(int i=1;i<=n;i++)
        {
            if(sum)
            {
                q[i].x++;
                sum--;
            }
        }
        sort(q+1,q+1+n,cmp2);
        for(int i=1;i<=n;i++)
        {
            if(i>1)printf(" ");
            printf("%d",q[i].x);
        }
        puts("");
    }
    return 0;
}