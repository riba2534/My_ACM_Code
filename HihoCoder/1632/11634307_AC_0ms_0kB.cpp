//#include <bits/stdc++.h>
//using namespace std;
//#define mem(a,b) memset(a,b,sizeof(a))
//const int N=200+20;
//int main()
//{
//
//    return 0;;
//}
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int n,x,ok,y;
    char map1[101][101];
    char map2[101][101];
    char str[10001];
    while(~scanf("%d",&n))
    {
        for(int i=0; i<n; i++)
        {
            scanf("%s",map1[i]);
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                map2[i][j]='@';
            }
            map2[i][n]='\0';
        }
        // printf("----------\n");
        str[0]=map1[0][0];
        ok=0,x=0,y=0;
        int len=1;
        while(len<n*n)
        {
            if(x==0&&ok==0)
            {
                if(y+1<n)
                {
                    y++;
                    ok=1;
                }
                else
                {
                    x++;
                    ok=1;
                }
            }
            else if(y==0&&ok==1)
            {
                if(x+1<n)
                {
                    x++;
                    ok=0;
                }
                else
                {
                    y++;
                    ok=0;
                }
            }
            else
            {
                if(ok==1)
                {
                    if(x+1<n&&y-1>=0)
                    {
                        x++;
                        y--;
                        ok=1;
                    }
                    else
                    {
                        y++;
                        ok=0;
                    }
                }
                else if(ok==0)
                {
                    if(x-1>=0&&y+1<n)
                    {
                        x--;
                        y++;
                        ok=0;
                    }
                    else
                    {
                        x++;
                        ok=1;
                    }
                }
            }
            //printf("%d %d %d\n",x,y,ok);
            str[len]=map1[x][y];
            len++;
        }
        str[len]='\0';
        x=y=0;
        int s=0;
//  for(int i=0;i<16;i++){
//            str[i]=char('A'+i);
//  }
        //printf("%s\n",str);
        for(int i=0; i<strlen(str);)
        {
            while(y<n && map2[x][y]=='@')
            {
                map2[x][y]=str[i++];
                y++;
            }
            y=y-1;
            x=x+1;
            while(x<n &&map2[x][y]=='@')
            {
                map2[x][y]=str[i++];
                x++;
            }
            y=y-1;
            x=x-1;
            while(y>=0 &&map2[x][y]=='@')
            {
                map2[x][y]=str[i++];
                y--;
            }
            x=x-1;
            y=y+1;
            while(x>=0&&map2[x][y]=='@')
            {
                map2[x][y]=str[i++];
                x--;
            }
            y=y+1;
            x=x+1;
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                printf("%c",map2[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
