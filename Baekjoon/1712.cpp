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
A�� �������, B �������

�������, �������, ��Ʈ�� ����

1) A > C�� -1

A + (B * i) < C * i
1000 + (70 * i) <= 170 * i
i = 11


170 - 70 = 100
1000 / 100 = 11

a + b / (c - b)
������ ������ +1
*/