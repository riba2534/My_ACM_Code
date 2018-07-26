 
#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
  
using namespace std;  
  
const int MAXN = 505 ;  
  
struct ArcNode  
{  
    int v1,v2;      //v1、v2表示可连通的楼  
    int cost;   //cost表示连通v1、v2的花费  
};  
  
int father[MAXN],add[MAXN];  
int v,e,s;  
  
bool cmp(const ArcNode &lhs, const ArcNode &rhs)  
{  
    return lhs.cost < rhs.cost;  
}  
  
void Kruskal(ArcNode *node)  
{  
    int i,j,k,x,y;  
    i=j=0;  
    s=0;  
    while(j<v-1)  
    {  
        x=father[node[i].v1-1];  
        y=father[node[i].v2-1];  
        if (x!=y)  
        {  
            for(k=0;k<v;k++)  
                if(father[k]==y)  
                    father[k]=x;  
            s+=node[i].cost;  
            ++j;  
        }  
        ++i;  
    }  
}  
  
  
int main()  
{  
    int n;  
    int i;  
    scanf("%d",&n);  
    while(n--)  
    {  
        scanf("%d%d",&v,&e);  
        ArcNode *node=new ArcNode[e];  
        for(i=0;i<e;i++)  
            scanf("%d%d%d",&node[i].v1,&node[i].v2,&node[i].cost);  
  
        sort(node,node+e,cmp);  
  
        for(i=0;i<v;i++)  
        {  
            scanf("%d",&add[i]);  
            father[i]=i;  
        }  
  
        sort(add,add+v);  
  
        Kruskal(node);      //运用克鲁斯卡尔算法求出cost值最小的连通图  
  
        printf("%d\n",s+add[0]);  
        delete[] node;  
        node=NULL;  
    }  
    return 0;  
}          