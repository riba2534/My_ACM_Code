 
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int N=1000+10;
struct dicTree
{
    struct Node
    {
        int sum;
        int next[26];
    } Tree[200000];
    int sz,root;
    int newnode()
    {
        for(int i=0; i<26; i++)
            Tree[sz].next[i]=-1;
        Tree[sz++].sum=0;
        return sz-1;
    }
    void init()
    {
        sz=0;
        root=newnode();
    }
    void insert(string s,int len)
    {
        int now=root;
        for(int i=0; i<len; i++)
        {
            int to=(int)(s[i]-'a');
            if(Tree[now].next[to]==-1)
                Tree[now].next[to]=newnode();
            now=Tree[now].next[to];
        }
        Tree[now].sum++;
    }
    int find(string s,int len)
    {
        int now=root;
        for(int i=0; i<len; i++)
        {
            int to=(int)(s[i]-'a');
            if(Tree[now].next[to]==-1)
                return 0;
            now=Tree[now].next[to];
        }
        return Tree[now].sum;
    }

};
dicTree dic;
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    string s,str;
    dic.init();
    cin>>t;
    int maxx=0;
    while(t--)
    {
        cin>>s;
        dic.insert(s,s.length());
        int num=dic.find(s,s.length());
        if(num>maxx)
        {
            maxx=num;
            str=s;
        }
    }
    cout<<str<<" "<<maxx<<endl;
    return 0;
}
        