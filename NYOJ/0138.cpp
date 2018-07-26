 
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
vector<bool>a(100000001);
int main()
{
    int n;
    int x=0;
    scanf("%d",&n);
    char b[15];
    while(n--)
    {
        memset(b,'\0',sizeof(b));
        scanf("%s",b);
        if(strcmp(b,"ADD")==0)
        {
            int m,n;
            scanf("%d",&m);
            while(m--)
            {
                scanf("%d",&n);
                a[n]=true;
            }
        }
        else if(strcmp(b,"QUERY")==0)
        {
            int k;
            scanf("%d",&k);
            while(k--)
            {
                int m;
                scanf("%d",&m);
                printf("%s\n",a[m]==true?"YES":"NO");
            }
        }
    }
    return 0;
}
        