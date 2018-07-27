#include <bits/stdc++.h>
using namespace std;
const int N=51000100+10;
int len,hw[N],ans;
char a[N],s[N*2];
void manacher()
{
    int maxright=0,mid;
    for(int i=1; i<=len; i++)
    {
        if(i<maxright)
            hw[i]=min(hw[2*mid-i],hw[mid]+mid-i);
        else
            hw[i]=1;
        for(; s[i+hw[i]]==s[i-hw[i]]; hw[i]++);
        if(hw[i]+i>maxright)
        {
            maxright=hw[i]+i;
            mid=i;
        }
    }
}
void init()
{
    s[0]=s[1]='#';
    for(int i=0; i<len; i++)
    {
        s[i*2+2]=a[i];
        s[i*2+3]='#';
    }
    len=len*2+2;
    s[len]=0;
}
int main()
{
    scanf("%s",a);
    len=strlen(a);
    init();
    manacher();
    ans=1;
    for(int i=0; i<len; i++)
        ans=max(ans,hw[i]);
    printf("%d\n",ans-1);
    return 0;
}
