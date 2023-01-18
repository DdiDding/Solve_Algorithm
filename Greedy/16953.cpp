#include<iostream>
#include<string>
#define MAX 1'000'000'000

typedef unsigned int integer;
using namespace std;

int main()
{
	integer A, B;
	cin >> A >> B;

	integer cnt = 1;
	while (A <= B && B != 0)
	{
		if (A == B)
		{
			cout << cnt;
			return 0;
		}

		if (B % 10 == 1)
		{
			B /= 10;
		}
		//홀수 체크
		else if ((B & 0x1) == 0x1)
		{
			cout << -1;
			return 0;
		}
		else
		{
			B /= 2;
		}
		++cnt;
	}

	cout << -1;
	return 0;
}
//
//
//int main()
//{
//	string A, B;
//	cin >> A >> B;
//
//	integer cnt = 1;
//	while (A.length() <= B.length() && B != "0")
//	{
//		if (A == B)
//		{
//			cout << cnt;
//			return 0;
//		}
//
//
//		if (B.back() == '1')
//		{
//			B.pop_back();
//		}
//		//홀수 체크
//		else
//		{//문자열을 어떻게 나누기 2를 하는가
//			B = to_string(stoi(B) / 2);
//		}
//		++cnt;
//	}
//
//	cout << -1;
//	return 0;
//}
