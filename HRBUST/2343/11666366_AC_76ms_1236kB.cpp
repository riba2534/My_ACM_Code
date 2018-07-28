#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
using namespace std;
const int N=1e5+20;
char s[N],t[N];
int vis[200];
int sear[200];
int main()
{
    while(~scanf("%s%s",s,t))
    {
        mem(vis,0);
        mem(sear,0);
        int tlen=strlen(t);
        int slen=strlen(s);
        for(int i=0; i<tlen; i++)
        {
            vis[t[i]]++;
            sear[t[i]]++;
        }
        int cnt=0,l=0,minl=0,minn=slen+1;
        for(int r=0; r<slen; r++)
            if(sear[s[r]])
            {
                if(--vis[s[r]]>=0)
                    cnt++;
                while(cnt==tlen)
                {
                    if(r-l+1<minn)
                        minl=l,minn=r-l+1;
                    if(sear[s[l]])
                        if(++vis[s[l]]>0)
                            cnt--;
                    l++;
                }
            }
        if(minn>slen) puts("");
        else
        {
            for(int i=minl; i<minl+minn; i++)
                printf("%c",s[i]);
            puts("");
        }
    }
    return 0;
}
