#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int vis[110][110];
int a,b,c;
int step;
int flag;
//记录状态
struct node
{
    int k1,k2;//当前水杯里面的水的量
    int op;//当前的操作
    int step;//步数
    int pre;//前一步的下标
} q[20000];
int id[20000];//最终操作在队列的编号
int lastindex;//最后一个的标号
void bfs()
{
    node now,to;
    int head,tail;
    head=tail=0;
    q[tail].k1=0;
    q[tail].k2=0;
    q[tail].op=0;
    q[tail].step=0;
    q[tail].pre=0;
    tail++;
    mem(vis,0);
//以上操作为初始化
    vis[0][0]=1;//初始状态入队
    while(head<tail)//队列非空时
    {
        now=q[head];//去队首
        head++;//出队
        for(int i=1; i<=6; i++)//遍历六种情况
        {
            if(i==1)//装满1
            {
                to.k1=a;
                to.k2=now.k2;
            }
            else if(i==2)//装满2
            {
                to.k1=now.k1;
                to.k2=b;
            }
            else if(i==3)//倒掉1
            {
                to.k1=0;
                to.k2=now.k2;
            }
            else if(i==4)//倒掉2
            {
                to.k1=now.k1;
                to.k2=0;
            }
            else if(i==5)//1->2
            {
                if(now.k1+now.k2<=b)//如果装不满b
                {
                    to.k1=0;
                    to.k2=now.k1+now.k2;
                }
                else
                {
                    to.k1=now.k1+now.k2-b;
                    to.k2=b;
                }
            }
            else if(i==6)//2->1
            {

                if(now.k1+now.k2<=a)//如果装不满a
                {
                    to.k1=now.k1+now.k2;
                    to.k2=0;
                }
                else
                {
                    to.k1=a;
                    to.k2=now.k1+now.k2-a;
                }
            }
            to.op=i;//记录操作
            if(!vis[to.k1][to.k2])//当前状态没有被标记
            {
                vis[to.k1][to.k2]=1;//标记
                to.step=now.step+1;//下一步
                to.pre=head-1;//记录下标

                q[tail].k1=to.k1;
                q[tail].k2=to.k2;
                q[tail].op=to.op;
                q[tail].step=to.step;
                q[tail].pre=to.pre;
                tail++;
                //以上为入队操作
                if(to.k1==c||to.k2==c)//满足条件
                {
                    flag=1;//状态标记为1
                    step=to.step;//最终的步数
                    lastindex=tail-1;//最终的标号
                    return;
                }
            }
        }
    }
}
int main()
{
    while(~scanf("%d%d%d",&a,&b,&c))
    {
        flag=0;
        step=0;
        bfs();
        if(flag)
        {
            printf("%d\n",step);
            id[step]=lastindex;
            for(int i=step-1; i>=1; i--)
            {
                id[i]=q[id[i+1]].pre;
            }
            for(int i=1; i<=step; i++)
            {
                if(q[id[i]].op==1)printf("FILL(1)\n");
                if(q[id[i]].op==2)printf("FILL(2)\n");
                if(q[id[i]].op==3)printf("DROP(1)\n");
                if(q[id[i]].op==4)printf("DROP(2)\n");
                if(q[id[i]].op==5)printf("POUR(1,2)\n");
                if(q[id[i]].op==6)printf("POUR(2,1)\n");
            }
        }
        else
            printf("impossible\n");

    }
    return 0;
}
