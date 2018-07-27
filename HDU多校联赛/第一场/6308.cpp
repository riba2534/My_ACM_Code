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
typedef long long ll;
const int N = 5e5 + 10;
const int inf = 0x3f3f3f3f;
void calc(int h, int m, int fen, int flag) //flag=1为+
{
    if (flag)
    {
        while (fen)
        {
            m++;
            if (m == 60)
            {
                m = 0;
                h++;
            }
            if (h == 24)
            {
                h = 0;
            }
            fen--;
        }
        printf("%02d:%02d\n", h, m);
    }
    else
    {
        while (fen)
        {
            m--;
            if (m == -1)
            {
                m = 59;
                h--;
            }
            if (h == -1)
            {
                h = 23;
            }
            fen--;
        }
        printf("%02d:%02d\n", h, m);
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int t;
    char str[100];
    scanf("%d", &t);
    while (t--)
    {
        int h, m;
        scanf("%d %d %s", &h, &m, str);
        int len = strlen(str);
        float x;
        char ch;
        sscanf(str, "UTC%c%f", &ch, &x);
        if (ch == '+')
        {
            if (x == 8.0)
            {
                printf("%02d:%02d\n", h, m);
            }
            else if (x > 8.0) //向上加
            {
                int fen = (int)((x - 8.0) * 60 + 0.01);
                calc(h, m, fen, 1);
            }
            else if (x < 8.0) //向下减
            {
                int fen = (int)((8.0 - x) * 60 + 0.01);
                calc(h, m, fen, 0);
            }
        }
        else if (ch == '-')
        {
            x = -x;
            int fen = (int)(((8.0) - x) * 60 + 0.01);
            calc(h, m, fen, 0);
        }
    }
    return 0;
}