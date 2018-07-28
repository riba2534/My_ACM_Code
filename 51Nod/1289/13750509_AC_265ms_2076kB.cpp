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
typedef long long ll;
const int N=1e5+10;
const int M=N*N;
int a[N];
int main()
{
    int n,x,y,l=0,ans=0;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&x,&y);
        if(y==0)
        {
            while(l&&a[l]<x)
                l--;
            if(l==0)ans++;
        }
        else
            a[++l]=x;
    }
    printf("%d\n",l+ans);
    return 0;
}
