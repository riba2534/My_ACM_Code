 
#include <stdio.h>
#include <algorithm>
using namespace std;
struct stu
{
	int x,y;
}a[10005];
bool cmp(stu x, stu y)
{
	return x.y < y.y;
}
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
		int n;
		scanf("%d",&n);
		int i, j, maxi;
		for (i = 0; i < n; i++)
		{
			scanf("%d %d",&a[i].x,&a[i].y);
		}
		sort(a, a + n, cmp);
		int ans = 1, temp = a[0].y;
		for (i = 1; i < n; i++)
		{
			if (a[i].x >= temp + 1)
				temp = a[i].y, ans++;
		}
		printf("%d\n",ans);

	}
	//getchar(); getchar();
	return 0;
}        