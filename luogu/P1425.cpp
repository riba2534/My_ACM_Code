#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(d<b)
    {
        d+=60;
        c--;
    }
    printf("%d %d\n",c-a,d-b);
    return 0;
}
