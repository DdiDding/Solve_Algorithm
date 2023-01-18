#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
using namespace std;
typedef unsigned int integer;
typedef unsigned long long ull;
typedef unsigned short BYTE;

#define BIG 0x0100
#define MID 0x0010
#define SML 0x0001

integer x, y;

BYTE Select(const integer & maxMove)
{
	ull dist = y - x - 1;
	ull temp = maxMove * ((long double)(1 + maxMove) / 2) - 1;

	if (temp <= dist) return BIG;
	if (maxMove - 1 == 1) return MID;
	if (temp - maxMove <= dist) return MID;
	return SML;
}

int main()
{
	ull temp = 4 * ((long double)(2 + 5) / 2);

	integer T;
	scanf("%u", &T);

	integer cnt;
	integer moveAmount;
	for (integer i = 0; i < T; ++i)
	{
		scanf("%u %u", &x, &y);
		if (x + 1 == y)
		{
			cout << 1 << "\n";
			continue;
		}
		++x;

		cnt = 1;
		moveAmount = 1; //현재 움직일 수 있는 중앙 값

		while (x + 1 < y)
		{
			switch (Select(moveAmount + 1))
			{
			case BIG: ++moveAmount; break;
			case SML: --moveAmount; break;
			default:break;
			}
			x += moveAmount;
			++cnt;
		}
		cnt++;
		cout << cnt << "\n";
	}
	return 0;
}

//#include <stdio.h>
//
//int main() {
//	int n;
//	scanf("%d", &n);
//
//	for (int i = 0; i < n; i++) 
//	{
//		int x, y;
//		scanf("%d %d", &x, &y);
//
//		//사이의 거리
//		int l = y - x;
//
//		int j = 1;
//
//		while ((l -= (++j) / 2) > 0)
//		{
//			printf("j의 값	: %d\n", j);
//			printf("j / 2	: %d\n", j / 2);
//			printf("l의 값	: %d\n\n", l);
//		};
//		printf("j의 값	: %d\n", j);
//		printf("j / 2	: %d\n", j / 2);
//		printf("l의 값	: %d\n\n", l);
//		printf("%d\n", j - 1);
//	}
//}