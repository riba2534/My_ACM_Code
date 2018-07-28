#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
typedef long long ll;
const int N=1000+20;
struct node
{
    int a,b,c,d,id,flag;
} a[N],now;
bool cmp(node a,node b)
{
    return a.d<b.d;
}
int main()
{
    int n;
    cin>>n;
    now.a=0,now.b=0,now.c=0,now.d=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i].a>>a[i].b>>a[i].c>>a[i].d;
        a[i].id=i;
        a[i].flag=1;
    }
    vector<node>v;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(a[i].a>a[j].a&&a[i].b>a[j].b&&a[i].c>a[j].c)
            {
                a[j].flag=0;
            }

        }
    }


    for(int i=1; i<=n; i++)
    {
        if(a[i].flag)
            v.push_back(a[i]);

    }
    sort(v.begin(),v.end(),cmp);
    cout<<v[0].id<<endl;

    return 0;
}
