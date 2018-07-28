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
#define N 100000+20
#define mod 10007
#define M 1000000+10
#define LL long long
using namespace std;
int pre[N],nxet[N];//前驱和后驱
int n,m;
int main()
{
    int q=1;
    while(~scanf("%d%d",&n,&m))
    {
        int tot=0;
        for(int i=1; i<=n; i++)
        {
            pre[i]=i-1;
            nxet[i]=i+1;
        }
        nxet[n]=0;
        int op,x,y;
        while(m--)
        {
            scanf("%d",&op);
            if(op!=4)
                scanf("%d%d",&x,&y);
            else
            {
                tot++;
                continue;
            }
            if((tot&1)&&op<3)//当链的状态为反转状态时，操作也逆着来
                op=3-op;
            if(op==1)
            {
                if(pre[y]==x)
                    continue;
                nxet[pre[x]]=nxet[x];//修改链表
                pre[nxet[x]]=pre[x];
                nxet[pre[y]]=x;
                pre[x]=pre[y];
                nxet[x]=y;
                pre[y]=x;
            }
            if(op==2)
            {
                if(nxet[y]==x)continue;
                nxet[pre[x]]=nxet[x];
                pre[nxet[x]]=pre[x];
                pre[nxet[y]]=x;
                nxet[x]=nxet[y];
                pre[x]=y;
                nxet[y]=x;
            }
            if(op==3)//要考虑相邻的情况
            {
                if(nxet[x]==y)
                {
                    int a=pre[x],b=nxet[y];
                    nxet[a]=y;
                    pre[y]=a;
                    pre[b]=x;
                    nxet[x]=b;
                    nxet[y]=x;
                    pre[x]=y;
                }
                else if(nxet[y]==x)
                {
                    int a=pre[y],b=nxet[x];
                    nxet[a]=x;
                    pre[x]=a;
                    pre[b]=y;
                    nxet[y]=b;
                    nxet[x]=y;
                    pre[y]=x;
                }
                else
                {
                    int a=nxet[y],b=pre[y];
                    nxet[pre[x]]=y;
                    pre[nxet[x]]=y;
                    nxet[pre[y]]=x;
                    pre[nxet[y]]=x;
                    nxet[y]=nxet[x];
                    pre[y]=pre[x];
                    nxet[x]=a;
                    pre[x]=b;
                }
            }
        }
        int *st,*ed;
        if(tot&1)//反转奇数次优化为反转一次
        {
            st=nxet;
            ed=pre;
        }
        else//偶数次等价于不反转
        {
            st=pre;
            ed=nxet;
        }
        LL sum=0;
        for(int i=1; i<=n; i++)
        {
            if(st[i]==0)
            {
                for(int j=1; i; i=ed[i],j++)
                    if(j&1)
                        sum+=i;
                break;
            }

        }
        printf("Case %d: %lld\n",q++,sum);
    }
    return 0;
}
