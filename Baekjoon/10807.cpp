#include <bits/stdc++.h>
using namespace std;
int ret[105];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n ; ++i)
	{
		cin >> ret[i];
	}

	int cnt = 0;
	int f; cin >> f;
	for (int i = 0; i < n; ++i)
	{
		if (ret[i] == f) ++cnt;
	}
	cout << cnt;
	return 0;
}