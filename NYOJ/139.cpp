 
#include <bits/stdc++.h>
using namespace std;
int jc[13]= {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
int get_num(string s)
{
    int len=s.size();
    int ans=0;
    for(int i=0; i<len; i++)
    {
        int num=0;
        for(int j=i+1; j<len; j++)
            if(s[i]>s[j])
                num++;
        ans+=num*jc[len-i-1];
    }
    return ans;
}
int main()
{
    int t;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        cout<<get_num(s)+1<<endl;
    }
    return 0;
}
        