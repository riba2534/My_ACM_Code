#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const int N=510*210;
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
        sum[now]=id;;
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
    bool vis[550];
    int query(char *s,int n,int id)
    {
        mem(vis,0);
        int len=strlen(s);
        int now=root;
        bool flag=false;
        for(int i=0; i<len; i++)
        {
            int to=s[i];
            now=next[now][to];
            int temp=now;
            while(temp!=root)
            {
                if(sum[temp]!=-1)
                {
                    vis[sum[temp]]=true;
                    flag=true;
                }
                temp=fail[temp];
            }
        }
        if(!flag) return false;
        printf("web %d:",id);
        for(int i=1; i<=n; i++)
            if(vis[i])
                printf(" %d",i);
        printf("\n");
        return true;
    }
};
dicTree ac;
char s[10010];
int main()
{
    int n,m;
    while(~scanf("%d",&n))
    {
        ac.init();
        for(int i=1; i<=n; i++)
        {
            scanf("%s",s);
            ac.insert(s,i);
        }
        ac.build();
        int ans=0;
        scanf("%d",&m);
        for(int i=1; i<=m; i++)
        {
            scanf("%s",s);
            if(ac.query(s,n,i))
                ans++;
        }
        printf("total: %d\n",ans);
    }
    return 0;
}
