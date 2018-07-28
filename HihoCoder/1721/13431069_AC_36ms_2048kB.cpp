#include <bits/stdc++.h>
using namespace std;
string s;
bool judge(int a,int b,int x)
{
    if(a==x) a++;
    if(b==x) b--;
    while(a<=b&&s[a]==s[b])
    {
        a++,b--;
        if(a==x) a++;
        if(b==x) b--;
    }
    return a>b;
}
int main()
{
    cin>>s;
    int len=s.size();
    int a=0,b=len-1;
    while(a<b)
    {
        if(s[a]!=s[b]) break;
        a++,b--;
    }
    int ans;
    if(a>b)
        ans=len/2;
    else if(judge(0,len-1,a))
        ans=a;
    else
        ans=b;
    while(s[ans]==s[ans-1])
        ans--;
    cout<<ans+1<<endl;
    return 0;
}
