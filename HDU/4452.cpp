#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 103
#define memset0(a) memset(a, 0, sizeof(a))

int N, M; //矩阵规模 模拟结束时刻
int dc[4] = {-1, 0, 1, 0};
int dr[4] = {0, 1, 0, -1};          //方向数组 d是direction
void change(int &x, int &y, int &op) //处理调头的函数 将走出边界的格数改变为在矩阵内移动的格数 并且改变方向
{

    if (y < 1)
    {
        y = 2 - y;
        op = 2;
    }
    else if (y > N)
    {
        y = 2 * N - y;
        op = 0;
    }
    else if (x < 1)
    {
        x = 2 - x;
        op = 1;
    }
    else if (x > N)
    {
        x = 2 * N - x;
        op = 3;
    }
}
void fun()
{
    char ch1, ch2;              //读取方向字符
    int s1, s2, t1, t2, d1, d2; //速度 左转间隔 方向
    getchar();
    scanf("%c%d%d", &ch1, &s1, &t1); //input
    getchar();
    scanf("%c%d%d", &ch2, &s2, &t2); //input
    scanf("%d", &M);                 //input
    if (ch1 == 'W')
        d1 = 0;
    else if (ch1 == 'E')
        d1 = 2;
    else if (ch1 == 'N')
        d1 = 3;
    else
        d1 = 1;
    if (ch2 == 'W')
        d2 = 0;
    else if (ch2 == 'E')
        d2 = 2;
    else if (ch2 == 'N')
        d2 = 3;
    else
        d2 = 1;
    int r1 = 1, c1 = 1, r2 = N, c2 = N; //初始位置
    for (int p = 1; p <= M; p++)
    {
        r1 += dr[d1] * s1;
        c1 += dc[d1] * s1;
        r2 += dr[d2] * s2;
        c2 += dc[d2] * s2; //移动
        change(r1, c1, d1);
        change(r2, c2, d2); //调头
        if (r1 == r2 && c1 == c2)
            swap(d1, d2); //相遇
        else
        {
            if (p  % t1 == 0)
                d1 = (d1 + 1) % 4;
            if (p  % t2 == 0)
                d2 = (d2 + 1) % 4;
        } //左转
    }
    printf("%d %d\n%d %d\n", r1, c1, r2, c2); //output
}
int main(void)
{
    //freopen("vs_cin.txt", "r", stdin);
    //freopen("vs_cout.txt", "w", stdout);

    while (~scanf("%d", &N) && N)
    { //input
        fun();
    }
}

// #include <cstdio>
// #include <cstring>
// #include <cctype>
// #include <stdlib.h>
// #include <string>
// #include <map>
// #include <iostream>
// #include <sstream>
// #include <set>
// #include <stack>
// #include <cmath>
// #include <queue>
// #include <vector>
// #include <algorithm>
// #include <list>
// using namespace std;
// #define mem(a, b) memset(a, b, sizeof(a))
// #define lson l, m, rt << 1
// #define rson m + 1, r, rt << 1 | 1
// #define inf 0x3f3f3f3f
// typedef long long LL;
// const int N = 5e4 + 20;
// const double pi = acos(-1);
// char s1[10], s2[10];
// int sp1, sp2, T1, T2, n;
// int F(char s) //方向：北N 0，东E 1，南S 2，西W 3
// {
//     if (s == 'N')
//         return 0;
//     if (s == 'E')
//         return 1;
//     if (s == 'S')
//         return 2;
//     return 3;
// }
// void K(int &x, int &y, int sp, int &z) //兔子跑一小时坐标变化
// {
//     if (z == 0)
//     {
//         x -= sp;
//         if (x <= 0)
//             x = 2 - x, z = (z + 2) % 4; //这里超出边界，自己模拟一下即可明白
//     }
//     else if (z == 1)
//     {
//         y += sp;
//         if (y > n)
//             y = 2 * n - y, z = (z + 2) % 4;
//     }
//     else if (z == 2)
//     {
//         x += sp;
//         if (x > n)
//             x = 2 * n - x, z = (z + 2) % 4;
//     }
//     else if (z == 3)
//     {
//         y -= sp;
//         if (y <= 0)
//             y = 2 - y, z = (z + 2) % 4;
//     }
// }
// void W(int &x) //左转，改变方向
// {
//     x = (x + 3) % 4;
// }
// int main()
// {
//     while (~scanf("%d", &n) && n)
//     {
//         scanf("%s%d%d", s1, &sp1, &T1);
//         scanf("%s%d%d", s2, &sp2, &T2);
//         int k;
//         scanf("%d", &k);
//         int x1 = 1, y1 = 1, t1 = 0, x2 = n, y2 = n, t2 = 0, f1, f2;
//         f1 = F(s1[0]);
//         f2 = F(s2[0]);
//         //x1,y1,表示兔子一坐标，t1表示跑了多久，f1表示当前方向，x2,y2,t2,f2同理。
//         while (k--)
//         {
//             K(x1, y1, sp1, f1);       //第一只兔子跑一小时
//             K(x2, y2, sp2, f2);       //
//             t1++, t2++;               //时间++
//             if (x1 == x2 && y1 == y2) //相遇
//             {
//                 swap(f1, f2); //方向交换
//                 continue;     //不继续运行下面，一定不左转。
//             }
//             if (t1 % T1 == 0)
//                 W(f1); //每T1小时就左转
//             if (t2 % T2 == 0)
//                 W(f2);
//         }
//         printf("%d %d\n%d %d\n", x1, y1, x2, y2);
//     }
// }