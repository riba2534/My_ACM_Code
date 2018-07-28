#include <cstdio>  
#include <cstring>  
#include <cstdlib>  
#include <cmath>  
#include <string>  
#include <iostream>  
#include <stack>  
#include <queue>  
#include <vector>  
#include <algorithm>  
#define mem(a,b) memset(a,b,sizeof(a))  
#define N 330  
#define M 10000+20  
#define MOD 1000000000+7  
#define inf 0x3f3f3f3f  
using namespace std;  
string s[1000000];  
int main()  
{  
    string str;  
    int k = 0;  
    while (cin >> str)  
    {  
        for (int i = 0; i < str.length(); i++)  
        {  
            if (isalpha(str[i]))  
            {  
                str[i] = tolower(str[i]);  
                s[k] += str[i];  
            }  
            else  
                k++;  
        }  
        k++;  
    }  
    sort(s, s + k);  
      
    for (int i = 1; i < k; i++)  
    {  
        if (s[i] != s[i - 1] && isalpha(s[i][0]))  
          
            cout << s[i] << endl;  
          
              
    }  
    return 0;  
}  