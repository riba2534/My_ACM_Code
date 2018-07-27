#include<iostream>
using namespace std;
int sta[1000],l,a=1;
void dfs(int k)
{
	for (int i=k/2;i>=1;i--) sta[++l]=i,dfs(i),l--,a++;
}
int main()
{
	int n;
	cin>>n;
	l+=1;
	sta[l]=n;
	dfs(n);
	cout<<a;
}