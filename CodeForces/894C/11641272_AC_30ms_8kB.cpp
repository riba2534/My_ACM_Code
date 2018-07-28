#include <bits/stdc++.h>
using namespace std;
const int N=1000+20;
int a[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<=n; i++)
    {
        if(a[i]%a[1]!=0)
        {
            puts("-1");
            return 0;
        }
    }
    printf("%d\n",2*n);
    for(int i=1; i<=n; i++)
        printf("%d %d ",a[i],a[1]);
    puts("");
    return 0;
}
