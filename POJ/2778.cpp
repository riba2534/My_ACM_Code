#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <sstream>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
const int N=110;
const int mod=100000;
struct Matrix
{
    int mat[110][110], n;
    Matrix() {}
    Matrix(int _n)
    {
        n = _n;
        mem(mat,0);
    }
    Matrix operator*(const Matrix &b) const
    {
        Matrix ret = Matrix(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                {
                    int tmp = (long long)mat[i][k] * b.mat[k][j] % mod;
                    ret.mat[i][j] = (ret.mat[i][j] + tmp) % mod;
                }
        return ret;
    }
};
Matrix mat_pow(Matrix a, int n)
{
    Matrix ret = Matrix(a.n);
    for (int i = 0; i < ret.n; i++)
        ret.mat[i][i] = 1;
    Matrix tmp = a;
    while (n)
    {
        if (n & 1)
            ret = ret * tmp;
        tmp = tmp * tmp;
        n >>= 1;
    }
    return ret;
}
struct dicTree
{
    int next[N][26],fail[N];
    bool end[N];
    int root,sz;
    int newnode()
    {
        for(int i=0; i<26; i++)
            next[sz][i]=-1;
        end[sz++]=0;
        return sz-1;
    }
    void init()
    {
        sz=0;
        root=newnode();
    }
    int getch(char ch)
    {
        if(ch=='A')return 0;
        if(ch=='C')return 1;
        if(ch=='G')return 2;
        if(ch=='T')return 3;
    }
    void insert(char *s)
    {
        int len=strlen(s);
        int now=root;
        for(int i=0; i<len; i++)
        {
            int to=getch(s[i]);
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
        for(int i=0; i<4; i++)
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
            if(end[fail[now]]==true)
                end[now]=true;
            for(int i=0; i<4; i++)
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
        Matrix res=Matrix(sz);
        for(int i=0; i<sz; i++)
            for(int j=0; j<4; j++)
                if(end[next[i][j]]==false)
                    res.mat[i][next[i][j]]++;
        return res;
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
        a=mat_pow(a,m);
        int ans=0;
        for(int i=0; i<ac.sz; i++)
            ans=(ans+a.mat[0][i])%mod;
        printf("%d\n",ans);
    }
    return 0;
}
