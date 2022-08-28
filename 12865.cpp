#include <iostream>
#include <algorithm>

using namespace std;
#define W first
#define V second

pair<int,int> arr[101];
int dp[100][100'002];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n, k; cin >> n >> k;

	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i].W >> arr[i].V;
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			if (j - arr[i].W >= 0)  dp[i][j] = max(dp[i - 1][j], dp[i-1][j - arr[i].W] + arr[i].V);
			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][k];

	return 0;
}