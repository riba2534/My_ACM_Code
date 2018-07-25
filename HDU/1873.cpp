#include <stdio.h>
#include <queue>
#include <string.h>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
struct node
{
    int yx;
    int cnt;
    friend bool operator < (node a,node b)
    {
        if(a.yx!=b.yx)
            return a.yx<b.yx;
        else
            return a.cnt>b.cnt;
    }
} now;
int main()
{
    int n;
    char s[10];
    int a,b;
    while(~scanf("%d",&n))
    {
        now.cnt=0;
        priority_queue<node>q[4];
        while(n--)
        {
            scanf("%s",s);
            if(strcmp(s,"IN")==0)
            {
                now.cnt++;
                scanf("%d%d",&a,&b);
                now.yx=b;
                q[a].push(now);
            }
            else
            {
                scanf("%d",&a);
                if(q[a].empty())
                {
                    printf("EMPTY\n");
                    continue;
                }
                else
                {
                    printf("%d\n",q[a].top().cnt);
                    q[a].pop();
                }

            }
        }
        mem(s,'\0');
    }

}
