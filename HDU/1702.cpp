#include <stdio.h>
#include <stack>
#include <cstring>
#include <queue>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        queue<int> q;
        stack<int> s;
        char str[10];
        scanf("%d %s",&n,str);
        if(strcmp(str,"FIFO")==0)
        {
            while(n--)
            {
                char zl[10];
                int x;
                scanf("%s",zl);
                if(strcmp(zl,"IN")==0)
                {
                    scanf("%d",&x);
                    q.push(x);
                }
                else if(strcmp(zl,"OUT")==0)
                {
                    if(!q.empty())
                    {
                        printf("%d\n",q.front());
                        q.pop();
                    }
                    else
                    {
                        printf("None\n");
                    }
                }
            }
        }
        else if(strcmp(str,"FILO")==0)
        {
            while(n--)
            {
                char zl[10];//з╕з╫звзр
                int x;
                scanf("%s",zl);
                if(strcmp(zl,"IN")==0)
                {
                    scanf("%d",&x);
                    s.push(x);
                }
                else if(strcmp(zl,"OUT")==0)
                {
                    if(!s.empty())
                    {
                        printf("%d\n",s.top());
                        s.pop();
                    }
                    else
                    {
                        printf("None\n");
                    }
                }
            }
        }

    }
    return 0;
}
