#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <stack>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 1000+20
#define mod 10007
#define M 1000000+10
#define LL long long
using namespace std;
string s0[15],s1[15],s2[15];
int main()
{
    s0[0]=" _ ";
    s0[1]="   ";
    s0[2]=" _ ";
    s0[3]=" _ ";
    s0[4]="   ";
    s0[5]=" _ ";
    s0[6]=" _ ";
    s0[7]=" _ ";
    s0[8]=" _ ";
    s0[9]=" _ ";
    s1[0]="| |";
    s1[1]="  |";
    s1[2]=" _|";
    s1[3]=" _|";
    s1[4]="|_|";
    s1[5]="|_ ";
    s1[6]="|_ ";
    s1[7]="  |";
    s1[8]="|_|";
    s1[9]="|_|";
    s2[0]="|_|";
    s2[1]="  |";
    s2[2]="|_ ";
    s2[3]=" _|";
    s2[4]="  |";
    s2[5]=" _|";
    s2[6]="|_|";
    s2[7]="  |";
    s2[8]="|_|";
    s2[9]=" _|";
    int a,b,c,d;
    while(cin>>a>>b>>c>>d)
    {
        cout<<s0[a]<<s0[b]<<s0[c]<<s0[d]<<endl<<s1[a]<<s1[b]<<s1[c]<<s1[d]<<endl<<s2[a]<<s2[b]<<s2[c]<<s2[d]<<endl;
    }
    return 0;
}


//
//    _  _  _
//  | _||_ |_
//  ||_  _||_|
// _  _     _
// _| _||_| _|
//|_  _|  ||_
