#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define debug() puts("what the fuck!!!")
#define ll long long
using namespace std;
const int N=1000010+100;
struct dicTree
{
    struct Node
    {
        int sum;
        int next[26];
    } Tree[N];
    int root, sz;
    int newnode()
    {
        for (int i = 0; i < 26; i++)
            Tree[sz].next[i] = -1;
        Tree[sz++].sum = 0;
        return sz - 1;
    }
    void init()
    {
        sz = 0;
        root = newnode();
    }
    void insert(string &s, int len)
    {
        int now = root;
        for (int i = 0; i < len; i++)
        {
            int to = (int)(s[i] - 'a');
            if (Tree[now].next[to] == -1)
                Tree[now].next[to] = newnode();
            now = Tree[now].next[to];
            Tree[now].sum++;
        }
    }
    int find(string &s, int len)
    {
        int now = root;
        for (int i = 0; i < len; i++)
        {
            int to = (int)(s[i] - 'a');
            if (Tree[now].next[to] == -1)
                return 0;
            now = Tree[now].next[to];
        }
        return Tree[now].sum;
    }
};
dicTree dic;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int flag=1;
    dic.init();
    string s;
    while(getline(cin,s))
    {
        if(s.size()==0)
        {
            flag=0;
            continue;
        }
        if(flag)
        {
            dic.insert(s,s.length());
        }
        else
        {
            cout<<dic.find(s,s.length())<<endl;
        }
    }
    return 0;
}
