#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pir;
const int inf=1e9+7;
const int N=200000+20;
int cnt[N];
int main()
{
    vector<pir>v;
    int n,m,num;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            cin>>num;
            v.push_back(make_pair(num,i));
        }
    sort(v.begin(),v.end());
    int ans=inf,tmp=0,p=0;
    for(int i=0; i<v.size(); i++)
    {
        while(p!=v.size()&&tmp<n)
        {
            int x=v[p].second;
            cnt[x]++;
            if(cnt[x]==1)
                tmp++;
            p++;
        }
        if(tmp==n)
            ans=min(ans,v[p-1].first-v[i].first);
        int x=v[i].second;
        cnt[x]--;
        if(cnt[x]==0)
            tmp--;
    }
    cout<<ans<<endl;
    return 0;
}
