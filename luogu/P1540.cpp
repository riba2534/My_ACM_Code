#include <bits/stdc++.h>
using namespace std;
const int N=1e4+6;
map<int,int>mp;
vector<int>v;

int num[N];
int main()
{
    int m,n,x,cnt=0,len=0,ans=0;
    scanf("%d%d",&m,&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&x);
        if(!mp[x])
        {
            if(cnt>=m)
            {
                //cnt--;
                mp[v[len++]]=0;
                v.push_back(x);
                mp[x]=1;
            }
            else
            {
                v.push_back(x);
                mp[x]=1;
                cnt++;
            }
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
