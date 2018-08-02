#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
string s1, s2;
int main()
{
    vector<int> v;
    int n;
    cin >> n >> s1 >> s2;
    for (int i = 0; i < n; i++)
    {
        int pos = s1.find(s2[i], i);
        if (pos == -1)
        {
            cout << -1 << endl;
            return 0;
        }
        while (pos > i)
        {
            swap(s1[pos - 1], s1[pos]);
            v.push_back(pos--);
        }
    }
    cout << v.size() << endl;
    for (auto num : v)
        cout << num << " ";
    cout << endl;

    return 0;
}