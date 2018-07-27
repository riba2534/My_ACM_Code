#include<iostream>
using namespace std;
int main()
{
    int x,n;
    cin>>x>>n;
    int sum=1;
    while(n--)
    {
        sum=sum+sum*x;
    }
    cout<<sum<<endl;
    return 0;
}
