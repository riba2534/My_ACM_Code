 
#include<stdio.h>
#include <string.h>
int main()
{
    int t;
    char s[105];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        int n=strlen(s);
        int flag=0;
        while(1)
        {
            if(n%2!=0)
                break;
            for(int i=0; i<n/2; i++)
            {
                if(s[i]!=s[n-i-1])
                {
                    flag=1;
                    break;
                }
            }
            if(flag)
            {
                break;
            }
            else
                n=n/2;
        }
        printf("%d\n",n);
    }
    return 0;
}
        