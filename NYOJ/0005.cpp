 
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int N=1e5+20;
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
int kmp_count(string s,string t)
{
    int ans=0,i,j=0;
    int slen=s.length(),tlen=t.length();
    if(slen==1&&tlen==1)
    {
        if(s[0]==t[0])
            return 1;
        else
            return 0;
    }
    get_next(t);
    for(int i=0; i<slen; i++)
    {
        while(j>0&&s[i]!=t[j])
            j=nxt[j];
        if(s[i]==t[j])
            j++;
        if(j==tlen)
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
    cin>>t;
    while(t--)
    {
       // mem(nxt,0);
        string s1,s2;
        cin>>s1>>s2;
        cout<<kmp_count(s2,s1)<<endl;
    }
    return 0;
}
        