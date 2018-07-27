#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
typedef long long ll;
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
const int N=100+10;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a1,h1,a2,h2;
        cin>>a1>>h1>>a2>>h2;
        int f1=1,f2=1;
        int hh2=h2,hh1=h1;
        hh2-=a1;
        hh1-=a2;
        if(hh1>0)
        {
            if(hh2==h2)
            {
                printf("Invalid\n");
                continue;
            }
            else if(hh2<=0)
            {
                f2=0;
                printf("%d %d ",a1,hh1);
                printf("Discard\n");
            }
            else if(hh2>0)
            {
                printf("%d %d ",a1,hh1);
                printf("%d %d\n",a2,hh2);
            }
        }
        else
        {
          //  printf("Discard ");
            if(hh2==h2)
            {
                printf("Invalid\n");
                continue;
            }
            else if(hh2<=0)
            {
                printf("Discard ");
                f2=0;
                printf("Discard\n");
            }
            else if(hh2>0)
            {
                printf("Discard ");
                printf("%d %d\n",a2,hh2);
            }

        }
    }


    return 0;
}