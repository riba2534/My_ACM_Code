#include<cstdio>
#include<cstring>
#include<string>
#include<set>
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
#define N (1010)
#define ll long long
using namespace std;
int dis[60000];
int l,n,m;
int solve(int start,int end,int k)
{
    int cnt,last,mid;
    while(start<=end)
    {
        cnt=last=0;
        mid=(start+end)>>1;//midΪ��ǰ����С��������ֵ
        for(int i=1; i<=n+1; i++)
        {
            if(dis[i]-dis[last]<=mid)//dis[i]-dis[last]����ǰ����ʯͷ�ľ���
                cnt++;//cnt����Ҫȥ����ʯͷ������
            else
                last=i;//ִ�е���һ������֤����һ��ʯͷ����ȥ��������Ҫ��������d[i]-d[last]��ʱ����Ҫ����last
        }
        if(cnt>k)
            end=mid-1;
        else
            start=mid+1;
    }
    return start;
}

int main()
{
    scanf("%d%d%d",&l,&n,&m);
    dis[0]=0,dis[n+1]=l;
    for(int i=1; i<=n; i++)
        scanf("%d",&dis[i]);
    sort(dis,dis+n+1);
    printf("%d\n",solve(0,l,m));
    return 0;
}