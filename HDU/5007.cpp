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
#define N 100000+20
#define mod 10007
#define M 1000000+10
#define LL long long
using namespace std;
int main()
{
    string a;
    while(getline(cin,a))
    {
        for(int i=0; i<a.length(); i++)
        {
            if((a[i]=='A'&&a[i+1]=='p'&&a[i+2]=='p'&&a[i+3]=='l'&&a[i+4]=='e')||
                    (a[i]=='i'&&a[i+1]=='P'&&a[i+2]=='h'&&a[i+3]=='o'&&a[i+4]=='n'&&a[i+5]=='e')||
                    (a[i]=='i'&&a[i+1]=='P'&&(a[i+2]=='o'||a[i+2]=='a')&&a[i+3]=='d'))
                cout<<"MAI MAI MAI!"<<endl;
            if(a[i]=='S'&&a[i+1]=='o'&&a[i+2]=='n'&&a[i+3]=='y')
                cout<<"SONY DAFA IS GOOD!"<<endl;
        }
    }
    return 0;
}
