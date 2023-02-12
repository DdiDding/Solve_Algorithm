#include <bits/stdc++.h>
using namespace std;

long long int dp[101];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;

	for (int i = 6; i <= 100; ++i)
	{
		dp[i] = dp[i - 2] + dp[i - 3];
	}

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		cout << dp[n] << '\n';
	}

	return 0;
}