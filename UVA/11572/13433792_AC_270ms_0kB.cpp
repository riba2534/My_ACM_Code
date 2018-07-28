#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int N=2e5+10;
int a[N];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        set<int>s;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        int l=1,r=1,ans=1;
        s.insert(a[r]);
        r++;
        while(r<=n)
        {
            auto it=s.find(a[r]);
            if(it==s.end())
            {
                s.insert(a[r]);
                ans=max(ans,r-l+1);
                r++;
            }
            else
            {
                while(1)
                {
                    s.erase(a[l]);
                    l++;
                    if(s.find(a[r])==s.end())
                    {
                        s.insert(a[r]);
                        r++;
                        break;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
