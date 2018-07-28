#include <cstdio>

#define N 100000+20
#define mod 10007
#define M 1000000+10
#define LL long long
using namespace std;
int pre[N],next[N];
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
            next[i]=i+1;
        }
        next[n]=0;//使之成环，对最后寻找开头和结尾有用
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
                next[pre[x]]=next[x];
                pre[next[x]]=pre[x];
                next[pre[y]]=x;
                pre[x]=pre[y];
                next[x]=y;
                pre[y]=x;
            }
            else if(op==2)
            {
                if(next[y]==x)
                    continue;
                next[pre[x]]=next[x];
                pre[next[x]]=pre[x];
                pre[next[y]]=x;
                next[x]=next[y];
                pre[x]=y;
                next[y]=x;
            }
            else if(op==3)//注意op==3时，要对x和y相邻的情况特判
            {
                if(next[x]==y)
                {
                    int temp1=pre[x],temp2=next[y];
                    next[temp1]=y;
                    pre[y]=temp1;
                    pre[temp2]=x;
                    next[x]=temp2;
                    next[y]=x;
                    pre[x]=y;
                }
                else if(next[y]==x)
                {
                    int temp1=pre[y],temp2=next[x];
                    next[temp1]=x;
                    pre[x]=temp1;
                    pre[temp2]=y;
                    next[y]=temp2;
                    next[x]=y;
                    pre[y]=x;
                }
                else
                {
                    int temp1=next[y],temp2=pre[y];
                    next[pre[x]]=y;
                    pre[next[x]]=y;
                    next[pre[y]]=x;
                    pre[next[y]]=x;
                    next[y]=next[x];
                    pre[y]=pre[x];
                    next[x]=temp1;
                    pre[x]=temp2;
                }
            }
        }
        int *st,*ed;
        if(tot&1)//反转奇数次，最终优化为反转一次
        {
            st=next;//将数组地址赋给指针
            ed=pre;
        }
        else//反转偶数次就是不反转
        {
            st=pre;
            ed=next;
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
