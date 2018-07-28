#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;
const int N=1e3+20;
map<char,double>mp;
void debug()
{
    puts("---!!!");
}
void init()
{
    mp['C']=12.01;
    mp['H']=1.008;
    mp['O']=16.00;
    mp['N']=14.01;
}
int main()
{
    init();
    string s;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        double sum=0;
        for(int i=0; i<s.length(); i++)
        {
            char c=s[i];
           // printf("c=%c\n",c);
            if(isupper(s[i]))
            {
                //debug();
                int cnt=0;
                while(i+1<s.length()&&isdigit(s[i+1]))
                {
                    //debug();
                    cnt=cnt*10+(s[i+1]-'0');
                    i++;
                }
                if(cnt==0)sum+=mp[c];
                else sum+=mp[c]*cnt;
            }
        }
        printf("%.3lf\n",sum);
    }
    return 0;
}
