#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include <map>
#include<iostream>
#include <cmath>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define mod 10000007
#define debug() puts("what the fuck!!!")
#define N (1000020)
#define ll long long
using namespace std;
int a[2000];//田忌
int b[2000];//国王
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(int i=0; i<n; i++)
            scanf("%d",&b[i]);
        sort(a,a+n);
        sort(b,b+n);

        int tl=0,tr=n-1;//田忌的慢马和快马
        int ql=0,qr=n-1;//国王的慢马和快马
        int sum=0;
        while(tl<=tr)
        {
            if(a[tl]<b[ql])//当前田忌最慢的马小于国王最慢的马
            {
                sum--;//打一场,战败
                tl++;
                qr--;
            }
            else if(a[tl]>b[ql])//当前田忌最慢的马大于国王最慢的马
            {
                sum++;//获胜
                tl++;
                ql++;
            }
            else if(a[tl]==b[ql])//当前田忌最慢的马等于国王最慢的马
            {
                while(tl <= tr && ql <= qr)//一直到比赛结束
                {
                    if(a[tr] > b[qr]) //如果田忌最快的马比齐王最快的马要快
                    {
                        sum++;//获胜
                        tr--;
                        qr--;
                    }
                    else 
                    {
                        if(a[tl] < b[qr])//解除局势
                            sum--;
                        tl++;//为了防止速度都一样
                        qr--;
                        break;
                    }
                }
            }
        }
        printf("%d\n",sum*200);
    }
    return 0;
}


