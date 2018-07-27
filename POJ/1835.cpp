#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N 1000+20
#define inf 0x3f3f3f3f
#define M 1000000+2000
#define LL long long
using namespace std;
char s[100];
int step,x,y,z;
void go(int dir)
{
    switch(dir)
    {
        case 0:x+=step;break;
        case 1:y+=step;break;
        case 2:z+=step;break;
        case 3:x-=step;break;
        case 4:y-=step;break;
        case 5:z-=step;break;
        default:break;
    }
}
int main()
{
    int t,n;
    int head,dir,left,temp;
    scanf("%d",&t);
    while(t--)
    {
        head=2,dir=0,left=4,x=0,y=0,z=0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s%d",s,&step);
            switch(s[0])
            {
                case 'f':break;
                case 'b':dir=(dir+3)%6,left=(left+3)%6;break;
                case 'l':temp=left,left=(dir+3)%6,dir=temp;break;
                case 'r':temp=dir,dir=(left+3)%6,left=temp;break;
                case 'u':temp=head,head=(dir+3)%6,dir=temp;break;
                case 'd':temp=dir,dir=(head+3)%6,head=temp;break;
                default:break;

            }
            go(dir);
        }
        printf("%d %d %d %d\n",x,y,z,dir);

    }
    return 0;
}
