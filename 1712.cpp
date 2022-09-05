#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int a, b, c; cin >> a >> b >> c;

	int cnt = -1;
	int t = c - b;
	if (0 < t)
	{
		cnt = a / t;
		if (t * cnt <= a) ++cnt;
	}

	cout << cnt;
	return 0;
}

/*
A의 고정비용, B 가변비용

고정비용, 가변비용, 노트북 가격

1) A > C면 -1

A + (B * i) < C * i
1000 + (70 * i) <= 170 * i
i = 11


170 - 70 = 100
1000 / 100 = 11

a + b / (c - b)
나머지 있으면 +1
*/