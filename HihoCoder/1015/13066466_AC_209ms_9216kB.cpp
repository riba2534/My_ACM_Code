#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
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
int get_num(string s,string p)
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
    int t;
    string s,p;
    cin>>t;
    while(t--)
    {
        cin>>p>>s;
        cout<<get_num(s,p)<<endl;
    }
    return 0;
}
