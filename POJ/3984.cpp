#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int map[5][5];//��ͼ
int go[4][2]= {{1,0},{-1,0},{0,-1},{0,1}};//�ĸ�����
int pre[10000];//����Ѱ�Ҹ��׽ڵ�
bool vis[10][10];//�������
struct node
{
    int x,y,s;
};//�洢������Ϣ����ǰ����
int bfs(int x,int y)
{
    node now,to;//���ڵĺͽ�Ҫ�ߵ�
    now.x=x,now.y=y,now.s=0;
    queue<node>q;//��������
    vis[x][y]=1;//�߹��ı��Ϊ1
    q.push(now);//�������
    while(!q.empty())
    {
        now=q.front();
        if(now.x==4&&now.y==4)return now.s;//��������ʱ�����߹��Ĳ���
        q.pop();
        for(int i=0; i<4; i++)
        {
            int xx=now.x+go[i][0];
            int yy=now.y+go[i][1];
            if(xx>=0&&yy>=0&&xx<5&&yy<5&&map[xx][yy]==0&&vis[xx][yy]==0)//�ж��Ƿ�Խ��
            {
                vis[xx][yy]=1;//����߹���
                to.x=xx,to.y=yy,to.s=now.s+1;
                pre[xx*5+yy]=now.x*5+now.y;//�洢���꣬ת����һά��ʽ
                q.push(to);
            }
        }
    }
    return 0;
}
void myprint(int n)
{
    //printf("pre[%d]=(%d)\n",n,pre[n]);
    if(n==pre[n])return;
    myprint(pre[n]);//Ѱ�Ҹ��׽ڵ�
    printf("(%d, %d)\n",n/5,n%5);
}//���ݴ�ӡ·��
int main()
{
    mem(vis,0);
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            scanf("%d",&map[i][j]);//�����ͼ
    if(bfs(0,0))
    {
        printf("(0, 0)\n");//�ȴ�ӡ0 0
        myprint(4*5+4);//�ӣ�4,4����ʼ����
    }
    else
        printf("-1\n");
    return 0;
}
