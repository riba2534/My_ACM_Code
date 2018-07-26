 
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
#define ll long long  
using namespace std;  
int main()  
{  
    string a;  
    const ll zz=4294967295;  
    while(getline(cin,a))  
    {  
        while(1)  
        {  
            ll apple=a.find("apple");  
            if(apple!=zz)  
                a.replace(apple,5,"miss");  
            else  
                break;  
        }  
        while(1)  
        {  
            ll banana=a.find("banana");  
            if(banana!=zz)  
                a.replace(banana,6,"love");  
            else  
                break;  
        }  
        while(1)  
        {  
            ll orange=a.find("orange");  
            if(orange!=zz)  
                a.replace(orange,6,"kiss");  
            else  
                break;  
        }  
        cout<<a<<endl;  
    }  
    return 0;  
}          