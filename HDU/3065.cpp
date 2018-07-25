#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const int N=510*210;
char str[1010][100];
struct dicTree
{
    int next[N][128],sum[N],fail[N];
    int root,sz;
    int newnode()
    {
        for(int i=0; i<128; i++)
            next[sz][i]=-1;
        sum[sz++]=-1;
        return sz-1;
    }
    void init()
    {
        sz=0;
        root=newnode();
    }
    void insert(char *s,int id)
    {
        int len=strlen(s);
        int now=root;
        for(int i=0; i<len; i++)
        {
            int to=s[i];
            if(next[now][to]==-1)
                next[now][to]=newnode();
            now=next[now][to];
        }
        sum[now]=id;
    }
    void build()
    {
        queue<int>q;
        fail[root]=root;
        for(int i=0; i<128; i++)
        {
            if(next[root][i]==-1)
                next[root][i]=root;
            else
            {
                fail[next[root][i]]=root;
                q.push(next[root][i]);
            }
        }
        while(!q.empty())
        {
            int now=q.front();
            q.pop();
            for(int i=0; i<128; i++)
            {
                if(next[now][i]==-1)
                    next[now][i]=next[fail[now]][i];
                else
                {
                    fail[next[now][i]]=next[fail[now]][i];
                    q.push(next[now][i]);
                }
            }
        }
    }
    int num[1010];
    int query(char *s,int n)
    {
        mem(num,0);
        int len=strlen(s);
        int now=root;
        for(int i=0; i<len; i++)
        {
            int to=s[i];
            now=next[now][to];
            int temp=now;
            while(temp!=root)
            {
                if(sum[temp]!=-1)
                    num[sum[temp]]++;
                temp=fail[temp];
            }
        }
        for(int i=1; i<=n; i++)
            if(num[i])
                printf("%s: %d\n",str[i],num[i]);
    }
};
dicTree ac;
char s[2000000+20];

int main()
{
    int n,m;
    while(~scanf("%d",&n))
    {
        ac.init();
        for(int i=1; i<=n; i++)
        {
            scanf("%s",str[i]);
            ac.insert(str[i],i);
        }
        ac.build();
        scanf("%s",s);
        ac.query(s,n);
    }
    return 0;
}

