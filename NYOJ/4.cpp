 
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//class Num
//{
//public:
//	int num[10];
//};
//class num1 :public Num
//{
//public:
//	void sort_0()//排序
//	{
//		int *a=
//		//sort(num, num + 5);
//		for (int i = 0; i < 5; i++)
//			cout << num[i] << " ";
//	}
//};
//class num2 :public Num
//{
//public:
//	void reverse_0()//逆转
//	{
//
//	}
//};
//class num3 :public Num
//{
//public:
//	void average()//求平均值
//	{
//
//	}
//};
//int main()
//{
//
//	Num arry;
//	cout << "请输入5个整数\n";
//	for (int i = 0; i < 5; i++)
//		cin >> arry.num[i];
//	num1 a1;
//	a1.sort_0();
//	
//	
//
//
//	return 0;
//}
//


#include <stdio.h>
int main()
{
	int n;
	char a, b, c,t;
	scanf("%d",&n);
	while (n--)
	{
		getchar();
		scanf("%c%c%c",&a,&b,&c);
		if (a > b)
		{
			t = a;
			a = b;
			b = t;
		}
		if (a > c)
		{
			t = a;
			a = c;
			c = t;
		}
		if (b > c)
		{
			t = b;
			b = c;
			c = t;
		}
		printf("%c %c %c\n", a, b, c);
	}
	return 0;
}
        