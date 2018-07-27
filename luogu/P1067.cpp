#include <bits/stdc++.h>
using namespace std;
const int N=1e4+6;
int main()
{
    int n,x,flag=1;
    scanf("%d",&n);
    for(int i=n; i>1; i--)
    {
        scanf("%d",&x);
        if(x==1)
        {
            if(flag)
            {
                printf("x^%d",i);
                flag=0;
            }
            else
            {
                printf("+x^%d",i);
            }
        }
        else if(x==-1)
        {
            if(flag)
            {
                 printf("-x^%d",i);
                 flag=0;
            }
            else
                 printf("-x^%d",i);

        }
        else if(x!=0)
        {
            if(flag)
            {
                printf("%dx^%d",x,i);
                flag=0;
            }
            else
            {
                if(x>0)
                    printf("+%dx^%d",x,i);
                else
                    printf("%dx^%d",x,i);
            }
        }
    }
    scanf("%d",&x);
    if(x!=0)
    {
        if(x==1)
        {
            printf("+x");
        }
        else if(x==-1)
        {
            printf("-x");
        }
        else if(x>0)
        {
            printf("+%dx",x);
        }
        else if(x<0)
        {
            printf("%dx",x);
        }
    }
    scanf("%d",&x);
    if(x>0)
        printf("+%d\n",x);
    else if(x<0)
        printf("%d\n",x);
    return 0;
}
