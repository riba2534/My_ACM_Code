#include<cstdio>  
#include<cstring>  
#include<string>  
#include<set>  
#include<iostream>  
#include<stack>  
#include<queue>  
#include<vector>  
#include<algorithm>  
#define mem(a,b) memset(a,b,sizeof(a))  
#define inf 0x3f3f3f3f  
#define mod 10000007  
#define debug() puts("what the fuck!!!")  
#define N 100000+20  
#define ll longlong  
using namespace std;  
int a[100+20];  
int vis[100+20];  
int main()  
{  
    int n,x;  
    mem(vis,0);  
    scanf("%d%d",&n,&x);  
    for(int i=0; i<n; i++)  
    {  
        scanf("%d",&a[i]);  
        vis[a[i]]=1;  
    }  
    sort(a,a+n);  
    if(x==0)  
    {  
        if(a[0]==0)  
            puts("1");  
        else  
            puts("0");  
    }  
    else  
    {  
        int sum=0;  
        for(int i=0; i<x; i++)  
        {  
            if(!vis[i])  
                sum++;  
        }  
        if(vis[x])  
            sum++;  
        printf("%d\n",sum);  
    }  
    return 0;  
}  