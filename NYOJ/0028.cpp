 
#include <stdio.h>
#include <string.h>
const int maxn=20000;
int f[maxn];
int main()
{


        int i,j,n;
        scanf("%d",&n);
        memset(f,0,sizeof(f));
        f[0]=1;
        for(i=2; i<=n; i++)
        {
            int c=0;
            for(j=0; j<maxn; j++)
            {
                int s=f[j]*i+c;
               // printf("当前i=%d,j=%d,s=%d,f[%d]=%d\n",i,j,s,j,f[j]);
                f[j]=s%10;
                c=s/10;
                //printf("         当前c=%d,f[%d]=%d\n",c,j,f[j]);
            }
        }
        for(j=maxn-1; j>=0; j--)
        {
            if(f[j])
                break;
        }
               // printf("j=%d\n",j);
        for(i=j; i>=0; i--)
        {
            printf("%d",f[i]);
        }
        printf("\n");

    return 0;
}
        