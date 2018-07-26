 
#include <stdio.h>
int main()
{
    int t,n,a,b;
    scanf("%d",&t);
    while(t--)
    {
        int ans=0,cnt=0;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&a,&b);
            ans^=a%(b+1);
        }
        if(ans==0) puts("Lose");
        else puts("Win");
    }
    return 0;
}
        