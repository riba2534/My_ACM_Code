 
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n,m;
    while(~scanf("%d",&n))
    {
        int ans=0;
        while(n--)
        {
            scanf("%d",&m);
            ans=ans^m;
        }
        printf("%d\n",ans);
    }
    return 0;
}        