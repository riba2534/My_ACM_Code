#include <bits/stdc++.h>
using namespace std;

int a[110],b[110];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)&&(m||n))
    {
        for(int i=0; i<n; i++)scanf("%d",&a[i]);
        for(int i=0; i<m; i++)scanf("%d",&b[i]);
        sort(a,a+n);
        sort(b,b+m);
        vector<int>v(110);
        vector<int>::iterator it;
        it=set_difference(a,a+n,b,b+m,v.begin());
        v.resize(it-v.begin());
        if(v.size()==0)puts("NULL");
        else
        {
            for(it=v.begin(); it!=v.end(); ++it)
                cout<<*it<<" ";
            cout<<endl;
        }
    }
    return 0;
}
