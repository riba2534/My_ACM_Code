#include <bits/stdc++.h>
using namespace std;
const int N=2e5+20;
int a[N];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    int s=0;
    for(int i=1; i<=n; i++)
    {
        printf("%d\n",(s+a[i])/m);
        s=(s+a[i])%m;
    }
    return 0;
}
