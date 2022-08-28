#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100'001

int arr[MAX];
int dp[MAX];

int main()
{
	//1. Set initial value & Get input value
	ios::sync_with_stdio(0), cin.tie(0);
	int n, k; cin >> n >> k;

	fill_n(dp, MAX, 100'005);

	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		dp[arr[i]] = 1;
	}

	arr[0] = 0;

	//2. Set Dp table
	for (int i = 1; i <= n; ++i)
	{
		for (int j = arr[i]; j <= k; ++j)
		{
			dp[j] = min(dp[j], dp[j - arr[i]] + 1);
		}
	}

	//3. Print
	if (dp[k] == 100'005) cout << -1;
	else cout << dp[k];
	return 0;
}