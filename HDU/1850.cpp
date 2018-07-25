#include <bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        int ans=0,cnt=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            ans^=a[i];
        }
        if(ans==0)puts("0");
        else
        {
            for(int i=0; i<n; i++)
            {
                int k=ans^a[i];
                if(a[i]-k>0)
                    cnt++;
            }
            printf("%d\n",cnt);
        }
    }
    return 0;
}
