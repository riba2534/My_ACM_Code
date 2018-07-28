#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define debug() puts("what the fuck!!!")
#define ll long long
using namespace std;
const int N=1010;
int t,n,m,q=1,x,a,b;
struct node
{
    int x,y;
} zz[N];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        vector<int>num[N];
        scanf("%d%d%d",&n,&m,&x);
        while(x--)
        {
            scanf("%d%d",&a,&b);
            num[a].push_back(b+1);
        }
        int maxx=0,minn=0;
        for(int i=0; i<n; i++)
        {
            sort(num[i].begin(),num[i].end());
            int bad=num[i].size();
            if(bad==0)
            {
                if(m%3==0)
                    minn+=m/3;
                else
                    minn+=m/3+1;
                if(m&1)
                    maxx+=(m+1)/2;
                else
                    maxx+=m/2;
            }
            else
            {
                num[i].insert(num[i].begin(),0);
                num[i].insert(num[i].end(),m+1);
                for(int j=1; j<num[i].size(); j++)
                {
                    int ans=num[i][j]-num[i][j-1]-1;
                    if(ans&1)
                        maxx+=(ans+1)/2;
                    else
                        maxx+=ans/2;
                    if(ans-1>=0)
                        minn+=(ans-1)/3+1;
                }
            }
        }
        printf("Case #%d: %d %d\n",q++,maxx,minn);
    }
    return 0;
}
