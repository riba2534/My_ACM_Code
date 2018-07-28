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
int nxt[N],s[N],p[N];
int n,m;
void get_next()
{
    int j=0,k=-1;
    nxt[0]=-1;
    while(j<n)
        if(k==-1||p[j]==p[k])
            nxt[++j]=++k;
        else
            k=nxt[k];
}
int get_num()
{
    int ans=0;
    get_next();
    int i=0,j=0;
    while(i<n)
    {
        if(j==-1||s[i]==p[j])
        {
            i++;
            j++;
        }
        else
            j=nxt[j];
        if(j==m)
        {
            ans++;
            j=nxt[j];
        }
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&s[i]);
        if(i)s[i-1]=s[i]-s[i-1];
    }
    for(int i=0; i<m; i++)
    {
        scanf("%d",&p[i]);
        if(i)p[i-1]=p[i]-p[i-1];
    }
//    for(int i=0; i<n; i++)
//        printf("%d ",s[i]);
//    printf("\n");
//    for(int i=0; i<m; i++)
//        printf("%d ",p[i]);
//    printf("\n");
    m--;
    printf("%d\n",get_num());
    return 0;
}
