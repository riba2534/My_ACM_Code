 
#include<stdio.h>
#include <string.h>
#include<queue>
using namespace std;
int l,r,c,x1,y1,z1,flag;
char a[32][32][32];
int move[6][3]= {{0,0,1},{0,1,0},{1,0,0},{0,0,-1},{0,-1,0},{-1,0,0}};
struct node
{
    int xx;
    int yy;
    int zz;
    int step;
};
void bfs(int x,int y,int z)
{
    queue<node>q;
    node now,next;
    now.xx=x;
    now.yy=y;
    now.zz=z;
    now.step=0;
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        for(int i=0; i<6; i++)
        {
            next.xx=now.xx+move[i][0];
            next.yy=now.yy+move[i][1];
            next.zz=now.zz+move[i][2];
            next.step=now.step+1;
            if(a[next.xx][next.yy][next.zz]=='E')
            {
                printf("Escaped in %d minute(s).\n",next.step);
                flag=1;
                return ;
            }
            if(next.xx>=0&&next.yy>=0&&next.zz>=0&&next.xx<l&&next.yy<r&&next.zz<c&&a[next.xx][next.yy][next.zz]=='.')
            {
                q.push(next);
                a[next.xx][next.yy][next.zz]='#';
            }
        }
    }
}
int main()
{

    //freopen("Input.txt","r",stdin);
    while(scanf("%d%d%d",&l,&r,&c)&&(l||r||c))
    {
        memset(a,0,sizeof(a));
        flag=0;
        for(int i=0; i<l; i++)
        {
            for(int j=0; j<r; j++)
            {
                scanf("%s",a[i][j]);
                for(int k=0; k<c; k++)
                {
                    if(a[i][j][k]=='S')
                    {
                        x1=i;
                        y1=j;
                        z1=k;
                    }
                }
            }
        }
        bfs(x1,y1,z1);
        if(flag==0)
            printf("Trapped!\n");
    }
    return 0;
}
        