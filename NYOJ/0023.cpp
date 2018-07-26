 
#include <stdio.h>
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        if(n%(m+1)==0)
            printf("Lose\n");
        else
            printf("Win\n");
    }
    return 0;
}
        