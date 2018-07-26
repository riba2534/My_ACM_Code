 
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    int a1,b1,a2,b2,a3,b3;
    while(cin>>a1>>b1>>a2>>b2>>a3>>b3&&(a1||b1||a2||b2||a3||b3))
    {
        double len1=sqrt((double)(a2-a1)*(a2-a1)+(double)(b2-b1)*(b2-b1));
        double len2=sqrt((double)(a2-a3)*(a2-a3)+(double)(b2-b3)*(b2-b3));
        double len3=sqrt((double)(a3-a1)*(a3-a1)+(double)(b3-b1)*(b3-b1));
        double p=(len1+len2+len3)/2;
        double s=sqrt(p*(p-len1)*(p-len2)*(p-len3));
        cout<<setiosflags(ios::fixed)<<setprecision(1)<<s<<endl;
    }
    return 0;
}
        