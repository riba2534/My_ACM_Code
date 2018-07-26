 
#include <stdio.h>
#include <string.h>
int main()
{
    char a[5000];
    char b[5000];
    while(~scanf("%s%s",a,b))
    {
        int m1=0,m2=0;
        int len=strlen(a);
        for(int i=0;i<len;i++)
        {
            if(a[i]=='+')
                m1++;
            if(b[i]=='+')
                m2++;
        }
        if(m1!=m2)
        {
            printf("-1\n");
            continue;
        }
        int sum=0;
        for(int i=0;i<len;i++)
        {
            int j;

            if(a[i]!=b[i])
            {
                for(j=i+1;j<len;j++)
                {
                    if(a[j]==b[i])
                        break;
                }
                sum+=j-i;
                a[j]=a[i];
            }
        }
        printf("%d\n",sum);


    }
    return 0;
}
        