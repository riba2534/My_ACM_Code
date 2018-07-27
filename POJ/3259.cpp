//#include <cstdio>
//#include <cstring>
//#include <cstdlib>
//#include <cmath>
//#include <string>
//#include <iostream>
//#include <stack>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#define mem(a,b) memset(a,b,sizeof(a))
//#define N 3000+20
//#define M 100000+20
//#define inf 0x3f3f3f3f
//using namespace std;
//int n,m,w;
//struct node
//{
//    int s,e,t;
//}G[N];
//int main()
//{
//    int t;
//    cin>>t;
//    while(t--)
//    {
//        cin>>n>>m>>w;
//        for(int i=1;i<=m;i++)
//            cin>>G[i].s>>G[i].e>>G[i].t;
//        for(int i=1;i<=w;i++)
//
//
//
//    }
//    return 0;
//}
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int map[505][505],n,m,k,num=0;
int floyd()
{
    int i,j,k,f=0;
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                int t=map[i][k]+map[k][j];
                if(map[i][j]>t)map[i][j]=t;
                /*map[i][j]=min(map[i][j],map[i][k]+map[k][j]);*/
            }
            if(map[i][i]<0)return 1;
        }
    return f;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,j,a,b,c;
        scanf("%d%d%d",&n,&m,&k);
        memset(map,0x3f3f3f3f,sizeof(map));
        for(i=1; i<=n; i++)
            map[i][i]=0;
        for(i=1; i<=m; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(c<map[a][b])
                map[a][b]=map[b][a]=c;
        }
        for(i=1; i<=k; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            map[a][b]=-c;
        }
        //num++;
        int flag=floyd();
        if(!flag)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
