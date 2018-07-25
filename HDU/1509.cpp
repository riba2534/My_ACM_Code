//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//#include <map>
//#include <stack>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#define mem(a,b) memset(a,b,sizeof(a))
//using namespace std;
//struct node
//{
//    char str[100];
//    int s1;
//    int s2;
//    int cnt;
//    friend bool operator < (node a, node b)
//    {
//        if(a.s2!=b.s2)
//            return a.s2>b.s2;
//        else
//            return a.cnt>b.cnt;
//    }
//};
//int main()
//{
//    int k=0;
//    char s[10];
//    node node1;
//    priority_queue<node> q;
//    while(~scanf("%s",s))
//    {
//        if(strcmp(s,"GET")==0)
//        {
//            if(q.empty())
//            {
//                printf("EMPTY QUEUE!\n");
//                continue;
//            }
//            else
//            {
//                node1=q.top();
//                q.pop();
//                printf("%s %d\n",node1.str,node1.s1);
//            }
//
//        }
//        else if(strcmp(s,"PUT")==0)
//        {
//            scanf("%s%d%d",node1.str,&node1.s1,&node1.s2);
//            node1.cnt=k++;
//            q.push(node1);
//        }
//        mem(s,'\0');
//    }
//    return 0;
//}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
struct node
{
    int str[100];
    int s1;
    int s2;
    int cnt;
    friend bool operator < (node a, node b)
    {
        if(a.s2!=b.s2)
            return a.s2>b.s2;
        else
            return a.cnt>b.cnt;
    }
};
int main()
{
    int k=0;
    char s[10];
    priority_queue<node>q;
    node now;
    while(~scanf("%s",s))
    {
        if(strcmp(s,"GET")==0)
        {
            if(q.empty())
            {
                printf("EMPTY QUEUE!\n");
                continue;
            }
            else
            {
                now=q.top();
                q.pop();
                printf("%s %d\n",now.str,now.s1);
            }

        }
        else if(strcmp(s,"PUT")==0)
        {
            scanf("%s%d%d",now.str,&now.s1,&now.s2);
            now.cnt=k++;
            q.push(now);
        }
        mem(s,'\0');
    }

}
