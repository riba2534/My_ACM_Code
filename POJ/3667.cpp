#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;
const int N=50005+20;
int lsum[N<<2],rsum[N<<2],msum[N<<2],cover[N<<2];
/*
msum[rt]:��ǰ�˵�����������������շ���ĸ���
lsum[rt]:��ǰ�˵��������������������շ���ĸ���
rsum[rt]:��ǰ�˵�����������ҵ�����������շ���ĸ���
cover[rt]:lazy��ǣ�-1��������,0����������ÿ�,1��������
*/
void pushup(int rt,int m)//���ϸ���
{
    //���µ�ǰ�˵�����ҵ��������ʹ��ҵ����������
    lsum[rt]=lsum[rt<<1];
    rsum[rt]=rsum[rt<<1|1];
    if(lsum[rt]==m-(m>>1))//������������ס��
        lsum[rt]+=lsum[rt<<1|1];
    if(rsum[rt]==(m>>1))//������������ס��
        rsum[rt]+=rsum[rt<<1];
    //��������������ĸ���Ϊ:����������������������������Ⱥʹ����ҵ�������+���ҵ����������
    msum[rt]=max(lsum[rt<<1|1]+rsum[rt<<1],max(msum[rt<<1],msum[rt<<1|1]));
}
void pushdown(int rt,int m)
{
    if(~cover[rt])//�������ӳٱ��
    {
        cover[rt<<1]=cover[rt<<1|1]=cover[rt];
        msum[rt<<1]=lsum[rt<<1]=rsum[rt<<1]=cover[rt]?0:m-(m>>1);
        msum[rt<<1|1]=lsum[rt<<1|1]=rsum[rt<<1|1]=cover[rt]?0:(m>>1);
        cover[rt]=-1;
    }
}
void build(int l,int r,int rt)
{
    cover[rt]=-1;
    lsum[rt]=rsum[rt]=msum[rt]=r-l+1;
    if(l==r) return;
    int m=(l+r)>>1;
    build(lson);
    build(rson);
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if(L<=l&&r<=R)
    {
        msum[rt]=lsum[rt]=rsum[rt]=c?0:r-l+1;//���Ҫ������,�ͱ��0,�������ȥ��,�ͱ������ĳ���
        cover[rt]=c;//����lazy���
        return;
    }
    pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    if(L<=m) update(L,R,c,lson);
    if(R>m) update(L,R,c,rson);
    pushup(rt,r-l+1);
}
int query(int w,int l,int r,int rt)//��ѯ�ܷ���w��λ�õ�����˵�
{
    if(l==r) return l;
    pushdown(rt,r-l+1);
    int m=(l+r)>>1;
    if(msum[rt<<1]>=w)
        return query(w,lson);
    else if(rsum[rt<<1]+lsum[rt<<1|1]>=w)//���ҵ��������������� +������������������
        return m-rsum[rt<<1]+1;
    else
        return query(w,rson);
}
int main()
{
    int n,m,op,k,a,b;
    while(~scanf("%d%d",&n,&m))
    {
        build(1,n,1);
        while(m--)
        {
            scanf("%d",&op);
            if(op==1)
            {
                scanf("%d",&k);
                if(msum[1]<k)//��������������������С��kʱ
                    puts("0");
                else
                {
                    int p=query(k,1,n,1);//��ѯ��С�ķ���λ��
                    printf("%d\n",p);
                    update(p,p+k-1,1,1,n,1);//��������[p,p+k-1]
                }
            }
            else if(op==2)
            {
                scanf("%d%d",&a,&b);
                update(a,a+b-1,0,1,n,1);//��������[a,a+b-1]
            }
        }
    }
    return 0;
}
