 
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int N=1e5+20;
int main()
{
    int t,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&x);
        printf("%d\n",__builtin_popcount(x));
    }
    return 0;
}
        