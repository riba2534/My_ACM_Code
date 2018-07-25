#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N 200200
#define M 1000000
#define ll long long
using namespace std;
int main()
{
    int t,k=0;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case #%d: ",++k);
        int a[5],b[5];
        scanf("%d%d%d%d",&a[1],&a[2],&a[3],&a[4]);
        scanf("%d%d%d%d",&b[1],&b[2],&b[3],&b[4]);
        if(a[1]==b[1]&&a[2]==b[2]&&a[4]==b[4]&&a[3]==b[3])
            printf("POSSIBLE\n");
        else if(a[1]==b[2]&&a[2]==b[4]&&a[4]==b[3]&&a[3]==b[1])
            printf("POSSIBLE\n");
        else if(a[1]==b[4]&&a[2]==b[3]&&a[4]==b[1]&&a[3]==b[2])
            printf("POSSIBLE\n");
        else if(a[1]==b[3]&&a[2]==b[1]&&a[4]==b[2]&&a[3]==b[4])
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");

    }

    return 0;
}