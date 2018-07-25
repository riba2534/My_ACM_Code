#include<stdio.h>
#include<algorithm>
using namespace std;

#define For(a,b,c) for(int a = b; a <= c; a++)
#define mem(a,b) memset(a,b,sizeof(a))

int N, M;
char a[10];
int MAX[800000+50];

void Build(int l, int r, int rt)
{
    if(l == r)
    {
        scanf("%d",&MAX[rt]);
        return;
    }
    int m = (l+r)>>1;
    Build(l,m,rt<<1);
    Build(m+1,r,rt<<1|1);
    MAX[rt] = max(MAX[rt<<1], MAX[rt<<1|1]);
}

void Updata(int p, int num, int l, int r, int rt)
{
    if(l == r)
    {
        MAX[rt] = num;
        return;
    }
    int m = (l + r) >> 1;
    if(p <= m) Updata(p,num,l,m,rt<<1);
    else Updata(p,num,m+1,r,rt<<1|1);
    MAX[rt] = max(MAX[rt<<1], MAX[rt<<1|1]);
}

int Query(int ql, int qr, int l, int r, int rt)
{
    if(ql<=l &&  r<=qr) return MAX[rt];
    int m = (l+r)>>1;
    int ans = 0;
    if(ql <= m) ans = max(ans, Query(ql,qr,l,m,rt<<1));
    if(qr > m) ans = max(ans, Query(ql,qr,m+1,r,rt<<1|1));
    return ans;
}

int main()
{
    while(~scanf("%d %d",&N,&M))
    {
        Build(1,N,1);
        while(M--)
        {
            scanf("%s",a);
            if(a[0] == 'Q')
            {
                int l, r;
                scanf("%d%d",&l,&r);
                printf("%d\n",Query(l,r,1,N,1));
            }
            else
            {
                int p, num;
                scanf("%d%d",&p,&num);
                Updata(p,num,1,N,1);
            }
        }
    }
    return 0;
}
