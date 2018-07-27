#include <bits/stdc++.h>
using namespace std;
const int N=1e4+6;
struct node
{
    int a,b,c,d;
} zz[N];
int main()
{
    int n,a,b,g,k,x,y;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d%d%d",&a,&b,&g,&k);
        zz[i].a=a;
        zz[i].b=b;
        zz[i].c=a+g;
        zz[i].d=b+k;
    }
    scanf("%d%d",&x,&y);
    for(int i=n; i>=1; i--)
    {
        if(x>=zz[i].a&&x<=zz[i].c&&y>=zz[i].b&&y<=zz[i].d)
        {
            printf("%d\n",i);
            return 0;
        }
    }
    puts("-1");
    return 0;
}
