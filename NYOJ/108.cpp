 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
int sum[1000000+20];
int main()
{
    int n,m,x,a,b;
    while(~scanf("%d%d",&n,&m))
    {
        memset(sum,0,sizeof(sum));
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&x);
            sum[i]=x+sum[i-1];
        }
        while(m--)
        {
            scanf("%d%d",&a,&b);
            printf("%d\n",sum[b]-sum[a-1]);
        }
    }
    return 0;
}
        