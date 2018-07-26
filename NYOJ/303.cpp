 
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int inf=0x3f3f3f3f;
const int N=100+20;
int num[N];
int main()
{
    int t;
    string s;
    scanf("%d",&t);
    while(t--)
    {
        cin>>s;
        int len=s.length();
        if(s[0]>='0'&&s[0]<='9')
        {
            len=0;
            string ss="";
            int sum=atoi(s.c_str());
            while(sum)
            {
                if(sum%26)
                    num[len++]=sum%26;
                else
                {
                    num[len++]=26;
                    sum-=26;
                }
                sum/=26;
            }
            for(int i=len-1; i>=0; i--)
                printf("%c",num[i]+'A'-1);
            printf("\n");
        }
        else
        {
            int sum=0;
            int k=0;
            for(int i=len-1; i>=0; i--)
                sum+=(s[i]-'A'+1)*(int)pow(26,k++);
            cout<<sum<<endl;
        }
    }
    return 0;
}        