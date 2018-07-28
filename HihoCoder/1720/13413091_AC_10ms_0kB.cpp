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
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;
const int N=1000+20;
int vis[20];
int main()
{
    int p,q;
    cin>>p>>q;
    for(int i=1; i<=50000; i++)
    {
        int cnt=0;
        while(p<q)
        {
            cnt++;
            p*=10;
        }
        if(cnt>1)vis[0]=1;
        int tmp=p/q;
        vis[tmp]=1;
        p=p-q*tmp;
    }
    for(int i=0; i<10; i++)
        if(vis[i])printf("%d",i);
    puts("");
    return 0;
}
