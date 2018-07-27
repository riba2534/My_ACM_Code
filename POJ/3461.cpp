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
char s1[N],s2[N];
int next[N];
int len1,len2,n,m;
void get_next()
{
    int j=0,k=-1;
    next[0]=-1;
    while(j<len1)
    {
        if(k==-1||s1[j]==s1[k])
            next[++j]=++k;
        else
            k=next[k];
    }
}
int KMP_count()
{
    int ans=0;
    int i,j=0;
    if(len1==1&&len2==1)
    {
        if(s1[0]==s2[0])
            return 1;
        else
            return 0;
    }
    get_next();
    for(int i=0; i<len2; i++)
    {
        while(j>0&&s2[i]!=s1[j])
            j=next[j];
        if(s1[j]==s2[i])
            j++;
        if(j==len1)
        {
            ans++;
            j=next[j];
        }
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",s1,s2);
        len1=strlen(s1);
        len2=strlen(s2);
        printf("%d\n",KMP_count());
    }
    return 0;
}
