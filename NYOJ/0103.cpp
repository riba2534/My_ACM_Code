 
#include <bits/stdc++.h>
using namespace std;
string sum(string s1,string s2)
{
	if(s1.length()<s2.length())
	{
		string temp=s1;
		s1=s2;
		s2=temp;
	}
	int i,j;
	for(i=s1.length()-1,j=s2.length()-1; i>=0; i--,j--)
	{
		s1[i]=char(s1[i]+(j>=0?s2[j]-'0':0));   //注意细节
		if(s1[i]-'0'>=10)
		{
			s1[i]=char((s1[i]-'0')%10+'0');
			if(i) s1[i-1]++;
			else s1='1'+s1;
		}
	}
	return s1;
}
string add(string a, string b)
{
	string s;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int i = 0;
	int m, k = 0;
	while(a[i] && b[i])
	{
		m = a[i] - '0' + b[i] - '0' + k;
		k = m / 10;
		s += (m % 10 + '0');
		i++;
	}
	if(i == a.size())
	{
		while(i != b.size())
		{
			m = k + b[i] - '0';
			k = m / 10;
			s += m % 10 + '0';
			i++;
		}
		if(k) s += k + '0';
	}
	else if(i == b.size())
	{
		while(i != a.size())
		{
			m = k + a[i] - '0';
			k = m / 10;
			s += m % 10 + '0';
			i++;
		}
		if(k) s += k + '0';
	}
	reverse(s.begin(), s.end());
	return s;
}
int main()
{
	int t,q=1;
	cin>>t;
	string s1,s2;
	while(t--)
	{
		cin>>s1>>s2;
		printf("Case %d:\n",q++);
		cout<<s1<<" + "<<s2<<" = "<<add(s1,s2)<<endl;
	}
	return 0;
}
        