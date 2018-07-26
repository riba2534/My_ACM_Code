 
#include <bits/stdc++.h>
using namespace std;
int jc[13]= {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
int num[13];//num[i]存储从小到大第i个未用过的字母编号
void init()
{
    for(int i=0; i<13; i++)
        num[i]=i;
}
string get_string(int cnt)//逆展开
{
    string ans="";
    for(int i=0; i<12; i++)
    {
        int tmp=cnt/jc[11-i];
        ans+=num[tmp]+'a';
        for(int j=tmp; j<11; j++)
            num[j]=num[j+1];
        cnt%=jc[11-i];
    }
    return ans;
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        init();
        cout<<get_string(n-1)<<endl;
    }
    return 0;
}
        