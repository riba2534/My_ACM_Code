 
//#include <bits/stdc++.h>
//using namespace std;
//#define mem(a,b) memset(a,b,sizeof(a))
//const int N=100+20;
//int vis[N][N][N];
//
//struct node
//{
//    int cap[3];
//    int step;
//};
//int st[3],ed[3];
//int main()
//{
//    int t;
//    scanf("%d",&t);
//    while(t--)
//    {
//        for(int i=0;i<3;i++)scanf("%d",&st[i]);
//        for(int i=0;i<3;i++)scanf("%d",&ed[i]);
//
//
//    }
//    return 0;
//}
#include <cstdio>
#include <memory.h>
#include <queue>

using namespace std;

#define EMPTY    0

struct data_type
{
    int state[3];
    int step;
};

int cupCapacity[3], targetState[3];

bool visited[100][100][100];

bool AchieveTargetState(data_type current)
{
    for (int i = 0; i < 3; i++)
    {
        if (current.state[i] != targetState[i])
        {
            return false;
        }
    }
    return true;
}

void PourWater(int destination, int source, data_type &cup)
{
    int waterYield = cupCapacity[destination] - cup.state[destination];
    if (cup.state[source] >= waterYield)
    {
        cup.state[destination] += waterYield;
        cup.state[source] -= waterYield;
    }
    else
    {
        cup.state[destination] += cup.state[source];
        cup.state[source] = 0;
    }
}

int BFS(void)
{
    int i, j, k;
    data_type initial;
    queue<data_type> toExpandState;
    memset(visited, false, sizeof(visited));
    initial.state[0] = cupCapacity[0];
    initial.state[1] = initial.state[2] = 0;
    initial.step = 0;
    toExpandState.push(initial);
    visited[initial.state[0]][0][0] = true;
    while (!toExpandState.empty())
    {
        data_type node = toExpandState.front();
        toExpandState.pop();
        if (AchieveTargetState(node))
        {
            return node.step;
        }
        for (i = 0; i < 3; i++)
        {
            for (j = 1; j < 3; j++)
            {
                k = (i+j)%3;
                if (node.state[i] != EMPTY && node.state[k] < cupCapacity[k])
                {
                    data_type newNode = node;
                    PourWater(k, i, newNode);
                    newNode.step = node.step + 1;
                    if (!visited[newNode.state[0]][newNode.state[1]][newNode.state[2]])
                    {
                        visited[newNode.state[0]][newNode.state[1]][newNode.state[2]] = true;
                        toExpandState.push(newNode);
                    }
                }
            }
        }
    }
    return -1;
}

int main(void)
{
    int testNum;
    scanf("%d", &testNum);
    while (testNum -- != 0)
    {
        scanf("%d%d%d", &cupCapacity[0], &cupCapacity[1], &cupCapacity[2]);
        scanf("%d%d%d", &targetState[0], &targetState[1], &targetState[2]);
        printf("%d\n", BFS());
    }
    return 0;
}
        