 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char a;
        int b;
        getchar();
        scanf("%c%d",&a,&b);
        if(a>='A'&&a<='Z')
            printf("%d\n",a-64+b);
        if(a>='a'&&a<='z')
            printf("%d\n",-a+96+b);
    }
    return 0;
}
        