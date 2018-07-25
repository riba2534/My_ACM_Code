#include <bits/stdc++.h>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int N=1000+20;
const int M=2000+10;
int a[N],vis[M];
int main()
{
    int t,n,m,x;
    scanf("%d",&t);
    while(t--)
    {
        mem(vis,0);
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        //枚举子集
        for(int i=0; i<(1<<n); i++) //二进制有n位
        {
            int cur=0;
            for(int j=0; j<n; j++)
            {
                if(i&(1<<j))
                    cur+=a[j];
            }
            vis[cur]=1;
            for(int j=0; j<n; j++)
            {
                if(cur-a[j]>=0)
                    vis[cur-a[j]]=1;
            }
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d",&x);
            if(vis[x])puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
