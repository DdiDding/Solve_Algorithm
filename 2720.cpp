#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int t; cin >> t;
	const int q = 25, d = 10, n = 5, p = 1;

	int c;
	while (t--)
	{
		cin >> c;

		cout << c / q << " ";
		c %= q;
		cout << c / d << " ";
		c %= d;
		cout << c / n << " ";
		c %= n;
		cout << c / p << "\n";
	}
	return 0;
}