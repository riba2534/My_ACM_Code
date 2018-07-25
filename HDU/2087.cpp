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
#define N 1000010
#define ll longlong
using namespace std;
char s[1020],t[1020],nxt[1020];
int slen,tlen;
void getnext()
{
    int j=0,k=-1;
    nxt[0]=-1;
    while(j<tlen)
    {
        if(k==-1||t[j]==t[k])
            nxt[++j]=++k;
        else
            k=nxt[k];
    }
}
int kmp_cnt()
{
    int ans=0,i,j=0;
    if(slen==1&&tlen==1)
    {
        if(s[0]==t[0])
            return 1;
        else
            return 0;
    }
    getnext();
    for(int i=0;i<slen;i++)
    {
        while(j>0&&s[i]!=t[j])
            j=nxt[j];
        if(s[i]==t[j])
           j++;
        if(j==tlen)
        {
            ans++;
            j=0;//若两个不同的匹配没有交集则j=0,若存在交集则j=next[j]; 
        }
    }
    return ans;
}
int main()
{
    while(scanf("%s",s)&&s[0]!='#')
    {
        scanf("%s",t);
        mem(nxt,0);
        slen=strlen(s);
        tlen=strlen(t);
        printf("%d\n",kmp_cnt());
    }
    return 0;
}
