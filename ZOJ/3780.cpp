#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include<list>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define inf 0x3f3f3f3f
typedef long long ll;
const int N=500+50;
char s[N][N];
int vis[N][N],n;
stack<string>st;
string get_s(int x)
{
    stringstream ss;
    string str;
    ss<<x;
    ss>>str;
    return str;
}
int get_num()
{
    while(1)
    {
        //行
        int r=0,c=0,flag=0;//flag标记图中是否还有字符
        for(int i=n; i>=1; i--)
        {
            int f1=1,f2=0;//f1标记是否出现'O',f2标记是否出现'X'
            for(int j=1; j<=n; j++)
            {
                if(s[i][j]!='#')flag=1;
                if(s[i][j]=='X')f2=1;
                if(s[i][j]=='O')
                {
                    f1=0;
                    break;
                }
            }
            if(f1&&f2)
            {
                r=i;
                break;
            }
        }
        //列
        for(int i=n; i>=1; i--)
        {
            int f1=1,f2=0;//f1标记是否出现'X',f2标记是否出现'O'
            for(int j=1; j<=n; j++)
            {
                if(s[j][i]!='#')flag=1;
                if(s[j][i]=='O')f2=1;
                if(s[j][i]=='X')
                {
                    f1=0;
                    break;
                }
            }
            if(f1&&f2)
            {
                c=i;
                break;
            }
        }
        if(c>0)//c>0&&r==0
        {
            string res="C"+get_s(c);
            st.push(res);
            for(int i=1; i<=n; i++)s[i][c]='#';
        }
        else if(r>0)//r>0&&c==0
        {
            string res="R"+get_s(r);
            st.push(res);
            for(int i=1; i<=n; i++)s[r][i]='#';
        }
        else//r==0&c==0
        {
            if(flag)
                return 0;
            return 1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int t;
    //scanf("%d",&t);
    cin>>t;
    while(t--)
    {
        mem(vis,0);
        while(!st.empty())st.pop();
        //scanf("%d",&n);
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            //scanf("%s",s[i]+1);
            cin>>s[i]+1;
        }
        if(get_num()==0)
            cout<<"No solution"<<endl;
        else
        {
            while(st.size()>1)
            {
                cout<<st.top()<<" ";
                st.pop();
            }
            cout<<st.top()<<endl;
        }
    }
    return 0;
}
/*
2
4
OOOO
XXXX
OOXX
XOXX
*/