#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int t, n; cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> n;
		if (n == 1) cout << 2 << "\n";
		else
		{
			int add = n % 3 == 0 ? 0 : 1;
			cout << n / 3 + add << "\n";
		}
	}

	return 0;
}