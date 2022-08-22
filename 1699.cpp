#include <iostream>
#include <algorithm>
using namespace std;

int dp[100'001];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;

	dp[1] = 1;	dp[2] = 2;	dp[3] = 3;	dp[4] = 1;

	for (int i = 5; i <= n; ++i)
	{
		dp[i] = i;
		for (int j = 0; j *j <= i; ++j)
		{
			dp[i] = min(dp[i], dp[i - (j * j)] + 1);
		}
	}

	cout << dp[n];
	return 0;
}