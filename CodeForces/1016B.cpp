#include <bits/stdc++.h>
using namespace std;
const int N=2e5+20;
int nxt[N];
void get_next(string p)
{
    int len=p.length();
    int j=0,k=-1;
    nxt[0]=-1;
    while(j<len)
        if(k==-1||p[j]==p[k])
            nxt[++j]=++k;
        else
            k=nxt[k];
}
int get_num(string s,string p)//p在s中出现的次数
{
    int ans=0;
    int slen=s.length();
    int plen=p.length();
    get_next(p);
    int i=0,j=0;
    while(i<slen)
    {
        if(j==-1||s[i]==p[j])
        {
            i++;
            j++;
        }
        else
            j=nxt[j];
        if(j==plen)
        {
            ans++;
            j=nxt[j];
        }
    }
    return ans;
}
int main()
{
    int n,m,q;
    string s,t;
    cin>>n>>m>>q>>s>>t;
    int l,r;
    while(q--)
    {
        cin>>l>>r;
        string str=s.substr(l-1,r-l+1);
        cout<<get_num(str,t)<<endl;
    }
    return 0;
}
