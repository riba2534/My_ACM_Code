#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 142857
typedef long long ll;
const int N=5e5+20;
const int M=100000+10;
struct dicTree
{
    struct node
    {
        int next[128];
    } Tree[N];
    int sz,root;
    int newnode()
    {
        for(int i=0; i<128; i++)
            Tree[sz].next[i]=-1;
        sz++;
        return sz-1;
    }
    void init()
    {
        sz=0;
        root=newnode();
    }
    int query(int a,int b)
    {
        if(Tree[a].next[b]==-1)
        {
            Tree[a].next[b]=newnode();
            return Tree[a].next[b];
        }
        else
            return Tree[a].next[b];
    }
} dic;
int main()
{
    int t;
    string s;
    scanf("%d",&t);
    while(t--)
    {
        cin>>s;
        dic.init();
        queue<int>q;
        vector<int>v;
        q.push(dic.root);
        for(int i=0; i<s.size(); i++)
        {
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                int x=dic.query(u,s[i]);
                v.push_back(x);
            }
            q.push(dic.root);
            for(int j=0; j<v.size(); j++)
                q.push(v[j]);
            v.clear();
        }
        printf("%d\n",dic.sz-1);
    }
    return 0;
}
