 
#include <stdio.h>

#define N 102
#define M 102

int map[N][M];

void search(int i,int j)
{
    if(map[i][j-1])
    {
        map[i][j-1]=0;
        search(i,j-1);
    }
    if(map[i][j+1])
    {
        map[i][j+1]=0;
        search(i,j+1);
    }
    if(map[i-1][j])
    {
        map[i-1][j]=0;
        search(i-1,j);
    }
    if(map[i+1][j])
    {
        map[i+1][j]=0;
        search(i+1,j);
    }
}

int main()
{
    int t,n,m;
    int i,j,count;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        count=0;
        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
                scanf("%d",&map[i][j]);

        for(i=1; i<=n; i++)
            for(j=1; j<=m; j++)
                if(map[i][j])
                {
                    count++;
                    map[i][j]=0;
                    search(i,j);
                }
        printf("%d\n",count);
    }
    return 0;
}
        