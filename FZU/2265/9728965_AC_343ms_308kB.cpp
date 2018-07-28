#include <cstdio>  
#include <cstring>  
#include <string>  
#include <set>  
#include <map>  
#include <iostream>  
#include <cmath>  
#include <stack>  
#include <queue>  
#include <vector>  
#include <algorithm>  
#define mem(a,b) memset(a,b,sizeof(a))  
#define inf 0x3f3f3f3f  
#define mod 10000007  
#define debug() puts("what the fuck!!!")  
#define N (10000+200)  
#define ll long long  
using namespace std;  
int a[N];  
int b[N];  
int main()  
{  
    int t,n,q=1;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d",&n);  
        for(int i=0; i<n; i++)  
            scanf("%d",&a[i]);  
        for(int i=0; i<n; i++)  
            scanf("%d",&b[i]);  
        sort(a,a+n);  
        sort(b,b+n);  
        int sum=0;  
        for(int i=0; i<n; i++)  
        {  
            int m=upper_bound(b,b+n,a[i])-b;  
            sum+=n-m;  
        }  
        printf("Case %d: %.2lf\n",q++,double(n-(sum*1.0/n)));  
    }  
    return 0;  
}  