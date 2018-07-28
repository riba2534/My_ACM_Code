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
int pre[N],nextt[N];
int n,m;

int main()
{
    int T=0;
    while(~scanf("%d%d",&n,&m))
    {
        int tot=0;
        for(int i=1; i<=n; ++i)
        {
            pre[i]=i-1;
            nextt[i]=i+1;
        }
        nextt[n]=0;//使之成环，对最后寻找开头和结尾有用
        int op,x,y;
        for(int i=1; i<=m; ++i)
        {
            scanf("%d",&op);
            if(op!=4)
                scanf("%d%d",&x,&y);
            else
            {
                ++tot;
                continue;
            }
            if((tot&1)&&op<3)
                op=3-op;
            if(op==1)
            {
                if(pre[y]==x)
                    continue;
                nextt[pre[x]]=nextt[x];
                pre[nextt[x]]=pre[x];
                nextt[pre[y]]=x;
                pre[x]=pre[y];
                nextt[x]=y;
                pre[y]=x;
            }
            else if(op==2)
            {
                if(nextt[y]==x)
                    continue;
                nextt[pre[x]]=nextt[x];
                pre[nextt[x]]=pre[x];
                pre[nextt[y]]=x;
                nextt[x]=nextt[y];
                pre[x]=y;
                nextt[y]=x;
            }
            else if(op==3)//注意op==3时，要对x和y相邻的情况特判
            {
                if(nextt[x]==y)
                {
                    int temp1=pre[x],temp2=nextt[y];
                    nextt[temp1]=y;
                    pre[y]=temp1;
                    pre[temp2]=x;
                    nextt[x]=temp2;
                    nextt[y]=x;
                    pre[x]=y;
                }
                else if(nextt[y]==x)
                {
                    int temp1=pre[y],temp2=nextt[x];
                    nextt[temp1]=x;
                    pre[x]=temp1;
                    pre[temp2]=y;
                    nextt[y]=temp2;
                    nextt[x]=y;
                    pre[y]=x;
                }
                else
                {
                    int temp1=nextt[y],temp2=pre[y];
                    nextt[pre[x]]=y;
                    pre[nextt[x]]=y;
                    nextt[pre[y]]=x;
                    pre[nextt[y]]=x;
                    nextt[y]=nextt[x];
                    pre[y]=pre[x];
                    nextt[x]=temp1;
                    pre[x]=temp2;
                }
            }
        }
        int *st,*ed;
        if(tot&1)//反转奇数次，最终优化为反转一次
        {
            st=nextt;//将数组地址赋给指针
            ed=pre;
        }
        else//反转偶数次就是不反转
        {
            st=pre;
            ed=nextt;
        }
        LL ans=0;
        for(int i=1; i<=n; ++i)
        {
            if(!st[i])//找到开头
            {
                for(int j=1; i; i=ed[i],++j)
                    if(j&1)
                        ans+=i;
                break;
            }
        }
        printf("Case %d: %lld\n",++T,ans);
    }
    return 0;
}
