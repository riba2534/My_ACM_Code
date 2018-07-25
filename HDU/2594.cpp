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
    string s1,s2,s;
    while(cin>>s1>>s2)
    {
        s=s1+"#"+s2;
        get_next(s);
        int len=s.length();
        int ans=nxt[len];
        if(!ans)
            puts("0");
        else
            cout<<s.substr(0,ans)<<" "<<ans<<endl;
    }
    return 0;
}


