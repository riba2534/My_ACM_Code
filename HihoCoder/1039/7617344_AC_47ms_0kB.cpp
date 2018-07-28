#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
char abc[3]= {'A','B','C'};
string xiaochu(string str)
{
    string ss="";
    int l=str.length();
    if(l<=1)
        return str;
    for(int i=0; i<l-1; i++)
    {
        if(str[i]==str[i+1])
        {
            while(i+1<=l&&str[i]==str[i+1])
            {
                i++;
            }
        }
        else
        {
            ss+=str[i];
        }
    }
    if(str[l-1]!=str[l-2])
        ss+=str[l-1];
    return ss;
}
int main()
{
    string s;
    int t,max;
    cin>>t;
    while(t--)
    {
        max=0;
        cin>>s;
        for(int i=0; i<s.length()-1; i++)
        {
            for(int j=0; j<3; j++)
            {
                string str=s.substr(0,i+1)+abc[j]+s.substr(i+1);
                int len=str.length();
                str=xiaochu(str);
                while(len>str.length())
                {
                    len=str.length();
                    str=xiaochu(str);
                }
                if(s.length()-str.length()+1>max)
                    max=s.length()-str.length()+1;
            }
        }
        cout<<max<<endl;
    }
}


