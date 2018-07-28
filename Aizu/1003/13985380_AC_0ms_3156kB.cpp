#include <cstdio>
#include <cstring>
#include <cctype>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define inf 0x3f3f3f3f
typedef long long ll;
const int N = 1e6 + 10;
const double eps = 1e-6;
string e[10];
void init()
{
    e[0] = " ";
    e[1] = "',.!?";
    e[2] = "abcABC";
    e[3] = "defDEF";
    e[4] = "ghiGHI";
    e[5] = "jklJKL";
    e[6] = "mnoMNO";
    e[7] = "pqrsPQRS";
    e[8] = "tuvTUV";
    e[9] = "wxyzWXYZ";
}
int main()
{
    //freopen("in.txt", "r", stdin);
    string s;
    init();
    while (cin >> s)
    {
        int n = s.size();
        int j = 0;
        for (int i = 0; i < n;)
        {
            char ch = s[i];
            while (s[++i] == ch)
                j++;
            int k = s[i - 1] - '0';
            if (k == 0)
                for (int l = 0; l < j; l++)
                    cout << " ";
            else
            {
                j = j % e[k].size();
                cout << e[k][j];
            }
            j = 0;
        }
        cout << endl;
    }
    return 0;
}
