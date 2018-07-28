#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N=1024+10;

char s[N];
int buf[32][32];
int cnt;
void draw(const char *s,int &p,int r,int c,int w)
{
    char ch=s[p++];
    if(ch=='p')
    {
        draw(s,p,r,c+w/2,w/2);
        draw(s,p,r,c,w/2);
        draw(s,p,r+w/2,c,w/2);
        draw(s,p,r+w/2,c+w/2,w/2);
    }
    else if(ch=='f')
    {
        for(int i=r; i<r+w; i++)
            for(int j=c; j<c+w; j++)
                if(!buf[i][j])
                {
                    buf[i][j]=1;
                    cnt++;
                }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        mem(buf,0);
        for(int i=0; i<2; i++)
        {
            scanf("%s",s);
            int p=0;
            draw(s,p,0,0,32);
        }
        printf("There are %d black pixels.\n",cnt);
    }
    return 0;
}
