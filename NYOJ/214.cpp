 
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
#define N 100005
#define M 1000000+10
#define ll long long
using namespace std;
int a[100100];
int b[100100];
int main()
{
    int n;
    while(cin>>n)
    {
        int len=0;
        mem(a,0);mem(b,0);
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
        {
            int p=lower_bound(b,b+len,a[i])-b;
            b[p]=a[i];
            if(p==len)len++;
        }
//        for(int i=0;i<len;i++)
//            printf("b[%d]=%d\n",i,b[i]);
        cout<<len<<endl;
    }

    return 0;
}
        