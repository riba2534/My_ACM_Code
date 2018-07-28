#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+100;
char ans[N];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,sz = 0;
	for(int i = 1; i<=N; i++)
		ans[i]='a';
	cin >> n;
	for(int i = 0; i<n;  i++)
	{
		string s;
		int k,t=-1;
		cin >> s >> k;
		for(int j = 0; j<k; j++)
		{
			int p;
			cin >> p;
			sz = max(sz, p + (int)s.size() - 1);
			//  printf("p=%d,t=%d\n",p,t);
			for(int c = max(p, t); c<=s.size()+p-1; c++)
			{
				//    printf("c=%d,p=%d,c-p=%d\n",c,p,c-p);
				ans[c] = s[c-p];
			}
			t = p+s.size()-1;
			//    printf("t=%d\n",t);
		}
	}
	for(int i =1; i<=sz; i++)
		cout << ans[i];
	return 0;
}