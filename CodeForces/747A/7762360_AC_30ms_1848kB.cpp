#include <stdio.h>  
#include <string.h>  
#include <stack>  
#include <cmath>  
#include <queue>  
#include <algorithm>  
#define mem(a,b) memset(a,b,sizeof(a))  
using namespace std;  
int main()  
{  
    int n;  
    while(~scanf("%d",&n))  
    {  
        for(int i=sqrt(n); i<=n; i++)  
        {  
            if(n%i==0)  
            {  
                int a=i,b=n/i;  
                printf("%d %d\n",a>b?b:a,a<b?b:a);  
                break;  
            }  
        }  
    }  
    return 0;  
}  