// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct dicTree
{
    int fail;
    int next[26];
    int sum;
} ac[N];
int sz=0;
void insert(string s)
{
    int len=s.length();
    int now=0;
    for(int i=0; i<len; i++)
    {
        int to=s[i]-'a';
        if(ac[now].next[to]==0)
            ac[now].next[to]=++sz;
        now=ac[now].next[to];
    }
    ac[now].sum++;
}
void build()
{
    queue<int>q;
    for(int i=0; i<26; i++)
    {
        if(ac[0].next[i]!=0)
        {
            ac[ac[0].next[i]].fail=0;
            q.push(ac[0].next[i]);
        }
    }
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        for(int i=0; i<26; i++)
        {
            if(ac[now].next[i]!=0)
            {
                ac[ac[now].next[i]].fail=ac[ac[now].fail].next[i];
                q.push(ac[now].next[i]);
            }
            else
                ac[now].next[i]=ac[ac[now].fail].next[i];
        }
    }
}
int query(string s)
{
    int len=s.length();
    int now=0,ans=0;
    for(int i=0; i<len; i++)
    {
        int to=s[i]-'a';
        now=ac[now].next[to];
        for(int temp=now; temp&&ac[temp].sum!=-1; temp=ac[temp].fail)
        {
            ans+=ac[temp].sum;
            ac[temp].sum=-1;
        }
    }
    return ans;
}
int main()
{
    string s;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>s;
        insert(s);
    }
    ac[0].fail=0;
    build();
    cin>>s;
    cout<<query(s)<<endl;
    return 0;
}
