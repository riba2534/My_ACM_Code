//#include <stdio.h>
//#include <string.h>
//#include <iostream>
//#include <math.h>
//#include <stack>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#define mem(a,b) memset(a,b,sizeof(a))
//using namespace std;
//int main()
//{
//
//    return 0;
//}
#include  <cstdio>
#include  <cstring>
#include  <cmath>
#include  <algorithm>
#include  <iostream>
#include  <vector>
#include  <queue>
#include  <map>
#include  <stack>
#include  <utility>
#include  <string>
#define rep0(i,n) for(int i = 0; i < n; i++)
#define rep1(i,n) for(int i = 1; i <= n; i++)
#define pb push_back
using namespace std;
typedef long long LL;
const int maxn = 105;
const int maxm = 100005;
int cur,n, Q, t[maxm], k[maxm], d[maxm], sum[maxm];
vector<int> q[maxm];
struct Node
{
    int t,q;
 //   Node() {}
    Node(int tt, int qq)
    {
        t = tt, q = qq;
    }
    bool operator <(const Node &rhs) const
    {
        return t > rhs.t;
    }
};
priority_queue<Node> que;
bool Isusing[maxn], no[maxm];

int main()
{
    scanf("%d%d", &n, &Q);
    for(int i = 1; i <= Q; i++)
    {
        scanf("%d%d%d",&t[i], &k[i], &d[i]);
    }
    memset(Isusing,false,sizeof(Isusing));
    cur = n;
    for(int i = 1; i <= Q; i++)
    {
        while(!que.empty())
        {
            Node p = que.top();
            if(p.t >= t[i])
            {
                break;
            }
            if(p.t < t[i])
            {
                que.pop();
                cur += k[p.q];
                for(int i = 0; i < q[p.q].size(); i++)
                {
                    int u = q[p.q][i];
                    Isusing[u] = false;
                }
            }
        }
        if(cur < k[i])
        {
            no[i] = true;
            continue;
        }
        else
        {
            cur -= k[i];
            int s = 0, cc = 0;
            for(int j = 1; j <= n; j++)
            {
                if(!Isusing[j])
                {
                    q[i].push_back(j);
                    Isusing[j] = true;
                    s += j;
                    cc++;
                    if(cc >= k[i])
                    {
                        break;
                    }
                }
            }
            sum[i] += s;
            que.push(Node(t[i]+d[i]-1,i));
        }
    }
    for(int i = 1; i <= Q; i++)
    {
        if(no[i])
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n",sum[i]);
        }
    }
    return 0;
}
