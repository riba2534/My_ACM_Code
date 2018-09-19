#include<bits/stdc++.h>
using namespace std;

#define PI acos(-1.0)
#define inf 0x3f3f3f3f
typedef long long ll;
const int maxn=100;

int a[4];
int main()
{
    while(~scanf("%d%d%d",&a[0],&a[1],&a[2]))
    {
        sort(a,a+3);
        int f=a[2]%2;
        if(f==0)
                printf("Yes\n");
        else
        {
            if(a[0]*a[1]%2==0)
                printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
