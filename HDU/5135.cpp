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
#define N 100
#define M 1000000
#define ll long long
using namespace std;
struct node
{
    double l;
    int vis;
} a[N];
int cmp(node a,node b)
{
    return a.l>b.l;
}
double mj(double a,double b,double c)
{
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
int jc(double a,double b,double c)
{
    if(a+b>c&&a+c>b&&b+c>a)
        return 1;
    else
        return 0;
}
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%lf",&a[i].l);
            a[i].vis=0;
        }
        sort(a+1,a+n+1,cmp);
        double num=0.0;
        int flag;
        for(int i=1; i<=n; i++)
        {
            flag=0;
            if(a[i].vis==0&&flag==0)
            {
                for(int j=i+1; j<=n; j++)
                {
                    if(a[j].vis==0&&flag==0)
                    {
                        for(int k=j+1; k<=n; k++)
                        {
                            if(a[k].vis==0&&flag==0)
                            {
                                if(jc(a[i].l,a[j].l,a[k].l))
                                {
                                    //debug();
                                    num+=mj(a[i].l,a[j].l,a[k].l);
                                    a[i].vis=1;
                                    a[j].vis=1;
                                    a[k].vis=1;
                                    flag=1;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%.2lf\n",num);
    }
    return 0;
}
