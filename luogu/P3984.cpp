#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int N=200000+20;
const int inf=INFINITY;
int a[N];
int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    int sum=0;
    for(int i=0; i<n; i++)
    {
        if(i==n-1)
        {
            sum+=t;
            break;
        }
        if(a[i+1]-a[i]<t)
            sum+=a[i+1]-a[i];
        else
            sum+=t;
    }
    printf("%d\n",sum);
    return 0;
}
