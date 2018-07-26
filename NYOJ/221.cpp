 
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
const int N=1010;
string pre,in;
stack<char>ans;
void dfs(int l1,int r1,int l2,int r2)
{
    int i;
    ans.push(pre[l1]);
    for(i=l2; i<=r2; i++)
        if(pre[l1]==in[i])
            break;
    int j=l1+(i-l2+1);
    if(j<=r1&&i+1<=r2)  dfs(j,r1,i+1,r2);
    if(l1+1<=j-1&&l2<=i-1) dfs(l1+1,j-1,l2,i-1);
}
int main()
{
    while(cin>>pre>>in)
    {
        while(!ans.empty())ans.pop();
        int n=pre.length();
        dfs(0,n-1,0,n-1);
        int flag=1;
        while(!ans.empty())
        {
            printf("%c",ans.top());
            ans.pop();
        }
        puts("");
    }
    return 0;
}        