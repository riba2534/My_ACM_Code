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
#define N 1000000+20
#define ll longlong
using namespace std;
char s[N];
int nxt[N];
void get_next(int len)
{
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
    int n,q=1;
    while(~scanf("%d",&n)&&n)
    {
        scanf("%s",s);
        printf("Test case #%d\n",q++);
        get_next(n);
        for(int i=1; i<=n; i++)
        {
            int j=i-nxt[i];
            if(i%j==0&&i/j>1)
                printf("%d %d\n",i,i/j);
        }
        puts("");
    }
    return 0;
}
