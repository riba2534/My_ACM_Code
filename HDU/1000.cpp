#include <stdio.h>
#include <queue>
#include <string.h>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
char map[21][21];
int main()
{
    int m,n;
    while(~scanf("%d%d",&m,&n))
    printf("%d\n",m+n);
//    while(1)
//    {
//        scanf("%d%d",&m,&n);
//        if(m==0&&n==0)return 0;
//        int sx,sy,ex,ey,A,B,C,D,E,a,b,c,d,e;
//        for(int i=0; i<m; i++)
//            scanf("%s",map[i]);
//        for(int i=0; i<m; i++)
//            for(int j=0; j<n; j++)
//            {
//                if(map[i][j]=='S')
//                {
//                    sx=i;
//                    sy=j;
//                }
//                if(map[i][j]=='G')
//                {
//                    ex=i;
//                    ey=j;
//                }
//
//            }
//
//
//
//    }
    return 0;
}
