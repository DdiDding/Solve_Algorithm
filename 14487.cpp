#include <bits/stdc++.h>
using namespace std;
int ret[50'005];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> ret[i];
	}
	sort(ret, ret + n + 1, less<int>());
	cout << accumulate(ret, ret + n, 0);
	return 0;
}