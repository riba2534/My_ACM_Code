#include <stdio.h>
#include <string.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char a[1001];
        scanf("%s",a);
        int len=strlen(a);
        int b[1000];
        memset(b,0,sizeof(b));
        for(int i=0;i<len;i++)
        {
            b[a[i]]++;
        }
        int max=0, j=0;
        int i;
        for(i=0;i<1000;i++)
        {
            if(b[i]!=0)
            {
                if(b[i]>max)
                    max=b[i],j=i;
            }

        }
        printf("%c %d\n",j,max);

    }
    return 0;
}
