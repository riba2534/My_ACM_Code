#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
typedef unsigned long long ull;
using namespace std;
const int N=50;
struct Matrix
{
    ull mat[N][N];
    int n;
    Matrix() {}
    Matrix(int _n)
    {
        n=_n;
        mem(mat,0);
    }
    Matrix operator *(const Matrix &b)const
    {
        Matrix ret=Matrix(n);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                for(int k=0; k<n; k++)
                    ret.mat[i][j]+=mat[i][k]*b.mat[k][j];
        return ret;
    }
};
ull pow_m(ull a,int n)
{
    ull ans=1;
    ull tmp=a;
    while(n)
    {
        if(n&1)
            ans*=tmp;
        tmp*=tmp;
        n>>=1;
    }
    return ans;
}
Matrix pow_M(Matrix a,int n)
{
    Matrix ans=Matrix(a.n);
    for(int i=0; i<a.n; i++)
        ans.mat[i][i]=1;
    Matrix tmp=a;
    while(n)
    {
        if(n&1)
            ans=ans*tmp;
        tmp=tmp*tmp;
        n>>=1;
    }
    return ans;
}
struct dicTree
{
    int fail[N],next[N][26];
    bool end[N];
    int root,sz;
    int newnode()
    {
        for(int i=0; i<26; i++)
            next[sz][i]=-1;
        end[sz++]=false;
        return sz-1;
    }
    void init()
    {
        sz=0;
        root=newnode();
    }
    void insert(char *s)
    {
        int now=root;
        int len=strlen(s);
        for(int i=0; i<len; i++)
        {
            int to=s[i]-'a';
            if(next[now][to]==-1)
                next[now][to]=newnode();
            now=next[now][to];
        }
        end[now]=true;
    }
    void build()
    {
        queue<int>q;
        fail[root]=root;
        for(int i=0; i<26; i++)
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
            if(end[fail[now]])
                end[now]=true;
            for(int i=0; i<26; i++)
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
    Matrix get_mat()
    {
        Matrix ret=Matrix(sz+1);
        for(int i=0; i<sz; i++)
            for(int j=0; j<26; j++)
                if(end[next[i][j]]==false&&end[i]==false)
                    ret.mat[i][next[i][j]]++;
        for(int i=0; i<sz+1; i++)
            ret.mat[i][sz]=1;
        return ret;
    }
};
dicTree ac;
char s[N];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        ac.init();
        for(int i=0; i<n; i++)
        {
            scanf("%s",s);
            ac.insert(s);
        }
        ac.build();
        Matrix a=ac.get_mat();
        a=pow_M(a,m);
        ull res=0;
        for(int i=0; i<a.n; i++)
            res+=a.mat[0][i];
        res--;
        a=Matrix(2);
        a.mat[0][0]=26,a.mat[1][0]=a.mat[1][1]=1;
        a=pow_M(a,m);
        ull ans=a.mat[0][0]+a.mat[1][0]-1;
        ans-=res;
        printf("%llu\n",ans);
    }
    return 0;
}
