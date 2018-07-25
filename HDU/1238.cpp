#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N 100+20
#define ll longlong
using namespace std;
int t,n;
int nxt[N];
string str[150];
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
bool kmp(string p,string s)//判断s是不是p的子串
{
    int plen=p.length();
    int slen=s.length();
    int i=0,j=0;
    while(i<plen&&j<slen)
    {
        if(j==-1||p[i]==s[j])
        {
            i++;
            j++;
        }
        else
            j=nxt[j];
    }
    if(j==slen)
        return true;
    return false;
}
int pd(string s)
{
    int flag=0;
    get_next(s);
    for(int k=1; k<n; k++)
        if(!kmp(str[k],s))
        {
            flag=1;
            break;
        }
    if(!flag)
        return 1;
    else
        return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>str[i];
        string ans="";
        for(int i=1; i<=str[0].size(); i++)
        {
            for(int j=0; j<=str[0].size()-i; j++)
            {
                string op=str[0].substr(j,i);
                if(pd(op))
                {
                    if(ans.size()<op.size())
                        ans=op;
                }
                reverse(op.begin(),op.end());
                if(pd(op))
                {
                    if(ans.size()<op.size())
                        ans=op;
                }
            }
        }
        cout<<ans.size()<<endl;
    }
    return 0;
}
