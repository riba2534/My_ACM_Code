 
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
        {
            if(i&1)
            {
                for(int j=n*i-n+1; j<=n*i; j++)
                    printf("%d ",j);
            }
            else
            {
                for(int j=n*i; j>=n*i-n+1; j--)
                    printf("%d ",j);
            }
            printf("\n");
        }
    }
    return 0;
}
        