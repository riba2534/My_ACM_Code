#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 20000+20
#define mod 10007
#define M 1000000+10
#define LL long long
using namespace std;
string str[110];
void func(int n,int num)
{
    if(str[num]!="?")
    {
        cout<<str[num]<<endl;
        return ;
    }
    int l=1,r=n+1,i,j;
    for(i=num-1; i>=0; i--)
    {
        if(str[i]!="?")
        {
            l=i;
            break;
        }
    }
    for(i=num+1; i<=n+1; i++)
    {
        if(str[i]!="?")
        {
            r=i;
            break;
        }
    }
    if(l==0)
    {
        int t_r=r;
        r=r-num;
        while(r--)
            printf("left of ");
        cout<<str[t_r]<<endl;
        return;
    }
    if(r==n+1)
    {
        int t_l=l;
        l=num-l;
        while(l--)
            printf("right of ");
        cout<<str[t_l]<<endl;
        return ;
    }
    if(r-num==num-l)
    {
        cout<<"middle of "<<str[l]<<" and "<<str[r]<<endl;
        return;
    }
    if(r-num<num-l)
    {
        int t_r=r;
        r=r-num;
        while(r--)
            printf("left of ");
        cout<<str[t_r]<<endl;
        return;
    }
    if(r-num>num-l)
    {
        int t_l=l;
        l=num-l;
        while(l--)
            printf("right of ");
        cout<<str[t_l]<<endl;
        return ;
    }
}
int main()
{
    int n,m,num;
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
            cin>>str[i];
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d",&num);
            func(n,num);
        }
    }
    return 0;
}
