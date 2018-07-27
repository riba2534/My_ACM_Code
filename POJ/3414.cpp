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
//��¼״̬
struct node
{
    int k1,k2;//��ǰˮ�������ˮ����
    int op;//��ǰ�Ĳ���
    int step;//����
    int pre;//ǰһ�����±�
} q[20000];
int id[20000];//���ղ����ڶ��еı��
int lastindex;//���һ���ı��
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
//���ϲ���Ϊ��ʼ��
    vis[0][0]=1;//��ʼ״̬���
    while(head<tail)//���зǿ�ʱ
    {
        now=q[head];//ȥ����
        head++;//����
        for(int i=1; i<=6; i++)//�����������
        {
            if(i==1)//װ��1
            {
                to.k1=a;
                to.k2=now.k2;
            }
            else if(i==2)//װ��2
            {
                to.k1=now.k1;
                to.k2=b;
            }
            else if(i==3)//����1
            {
                to.k1=0;
                to.k2=now.k2;
            }
            else if(i==4)//����2
            {
                to.k1=now.k1;
                to.k2=0;
            }
            else if(i==5)//1->2
            {
                if(now.k1+now.k2<=b)//���װ����b
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

                if(now.k1+now.k2<=a)//���װ����a
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
            to.op=i;//��¼����
            if(!vis[to.k1][to.k2])//��ǰ״̬û�б����
            {
                vis[to.k1][to.k2]=1;//���
                to.step=now.step+1;//��һ��
                to.pre=head-1;//��¼�±�

                q[tail].k1=to.k1;
                q[tail].k2=to.k2;
                q[tail].op=to.op;
                q[tail].step=to.step;
                q[tail].pre=to.pre;
                tail++;
                //����Ϊ��Ӳ���
                if(to.k1==c||to.k2==c)//��������
                {
                    flag=1;//״̬���Ϊ1
                    step=to.step;//���յĲ���
                    lastindex=tail-1;//���յı��
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
