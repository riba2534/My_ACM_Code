#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10007
#define debug() puts("what the fuck!!!")
#define N 200000+20
#define ll long long
using namespace std;
int nxt[N];
string str[4500];
void get_next(string s)
{
    int len=s.length();
    int j=0,k=-1;
    nxt[0]=-1;
    while(j<len)
        if(k==-1||s[j]==s[k])
            nxt[++j]=++k;
        else
            k=nxt[k];
}
int main()
{
    int t,n;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        ll ans=0;
        get_next(s);
        for(int i=1; i<=n; i++)
            if(nxt[i])
                ans++;
        ans+=n;
        ans%=mod;
        cout<<ans<<endl;
    }
    return 0;
}


