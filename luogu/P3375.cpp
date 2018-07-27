#include <bits/stdc++.h>
using namespace std;
const int N=1000000+10;
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
void kmp(string s,string p)
{
    int slen=s.length();
    int plen=p.length();
    int i=0,j=0;
    get_next(p);
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
            printf("%d\n",i-plen+1);
            j=nxt[j];
        }
    }
}
int main()
{
    string s,p;
    cin>>s>>p;
    kmp(s,p);
    for(int i=1;i<=p.length();i++)
        printf("%d ",nxt[i]);
    return 0;
}
