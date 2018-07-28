#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const int N=1e6+20;
#define inf 0x3f3f3f3f
int a[N];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    printf("%d\n",a[k-1]);
    return 0;
}
