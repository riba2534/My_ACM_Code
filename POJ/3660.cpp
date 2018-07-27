#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N 100+20
#define M 100000+20
#define inf 0x3f3f3f3f
using namespace std;
int n,m;
int map[N][N];
int main()
{
    int a,b;
    while(~scanf("%d%d",&n,&m))
    {
        mem(map,0);
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&a,&b);
            map[a][b]=1;
        }
        int sum=0;
        for(int k=1; k<=n; k++)
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    if(map[i][k]&&map[k][j])//��ӱ��ֱ��
                        map[i][j]=1;
                
        for(int i=1; i<=n; i++)
        {
            int k=0;
            for(int j=1; j<=n; j++)
                k+=map[i][j]+map[j][i];
            if(n-1==k)//���һͷţ����������ţ�Ĺ�ϵȷ���˵Ļ�����������Ҳ��ȷ���ˡ�  
                sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
