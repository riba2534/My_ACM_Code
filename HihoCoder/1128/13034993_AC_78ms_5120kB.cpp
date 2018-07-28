#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const int N=1e6+20;
#define inf 0x3f3f3f3f
int a[N];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int l=0,r=n-1;
    int ans=N;
    while(l<=r)
    {
        int m=(l+r)>>1;
        if(a[m]==k)
        {
            ans=m;
            break;
        }
        else if(a[m]>k)
            r=m-1;
        else
            l=m+1;
    }
    if(ans==N)
        puts("-1");
    else
        printf("%d\n",ans+1);
    //    int ans=lower_bound(a,a+n,k)-a+1;
    //    if(a[ans-1]==k)
    //        printf("%d\n",ans);
    //    else
    //        puts("-1");
    return 0;
}
