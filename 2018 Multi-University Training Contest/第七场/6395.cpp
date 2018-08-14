#include <bits/stdc++.h>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
typedef long long ll;
const ll mod = 1e9 + 7;
const ll N = 3;
struct Matrix
{
    ll a[N][N];
    Matrix()
    {
        mem(a, 0);
    }
    void init()
    {
        mem(a, 0);
        for (ll i = 0; i < N; i++)
            a[i][i] = 1;
    }
};
void print(Matrix a)
{
    for (ll i = 0; i < N; i++)
    {
        for (ll j = 0; j < N; j++)
            printf("%lld ", a.a[i][j]);
        puts("");
    }
}
Matrix mul(Matrix a, Matrix b)
{
    Matrix ans;
    for (ll i = 0; i < N; i++)
        for (ll j = 0; j < N; j++)
            for (ll k = 0; k < N; k++)
            {
                ans.a[i][j] += a.a[i][k] * b.a[k][j];
                ans.a[i][j] %= mod;
            }
    return ans;
}
Matrix mat_pow(Matrix a, ll n)
{
    Matrix ans;
    ans.init();
    while (n)
    {
        if (n & 1)
            ans = mul(ans, a);
        a = mul(a, a);
        n >>= 1;
    }
    return ans;
}
void solve()
{
    ll a, b, c, d, p, n;
    scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &p, &n);
    if (n == 1)
    {
        printf("%lld\n", a);
        return;
    }
    Matrix A, B; //分别被为初始矩阵和转置矩阵
    A.a[0][0] = b;
    A.a[0][1] = a;
    B.a[0][0] = d;
    B.a[0][1] = 1;
    B.a[1][0] = c;
    B.a[2][0] = 1;
    B.a[2][2] = 1;
    if (p >= n)
    {
        for (ll i = 3, j; i <= n; i = j + 1)
        {
            j = p / (p / i);
            A.a[0][2] = p / i;
            Matrix po = mat_pow(B, min(j - i + 1, n - i + 1));
            A = mul(A, po);
        }
    }
    else
    {
        for (ll i = 3, j; i <= p; i = j + 1)
        {
            j = p / (p / i);
            A.a[0][2] = p / i;
            Matrix po = mat_pow(B, j - i + 1);
            A = mul(A, po);
        }
        Matrix po;
        A.a[0][2] = 0;
        if (p < 3)
            po = mat_pow(B, n - 2);
        else
            po = mat_pow(B, n - p);
        A = mul(A, po);
    }
    printf("%lld\n", A.a[0][0]);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    ll t;
    scanf("%lld", &t);
    while (t--)
        solve();
    return 0;
}