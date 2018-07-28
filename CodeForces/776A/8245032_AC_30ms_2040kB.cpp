#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N 200+20
#define M 100000+20
#define inf 0x3f3f3f3f
using namespace std;
int main()
{
    string s1,s2,s3,s4;
    cin>>s1>>s2;
    int n;
    cin>>n;
    cout<<s1<<" "<<s2<<endl;
    for(int i=1; i<=n; i++)
    {
        cin>>s3>>s4;
        if(s3==s1)
            s1=s4;
        else
            s2=s4;
        cout<<s1<<" "<<s2<<endl;
    }
    return 0;
}