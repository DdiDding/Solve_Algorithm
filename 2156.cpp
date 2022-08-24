#include <iostream>
#include <algorithm>

using namespace std;

int dp[10'001] = { 0, };
int arr[10'001] = { 0, };

int main()
{
	//1. Get input value
	ios::sync_with_stdio(0), cin.tie(0);

	int n; cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
	}

	//2. Set initial value
	dp[1] = arr[1];
	dp[2] = arr[2] + arr[1];

	for (int i = 3; i <= n; ++i)
	{
		dp[i] = max(dp[i - 3] + arr[i - 1], dp[i - 2]) + arr[i];
		dp[i] = max(dp[i - 1], dp[i]);
	}

	//3. Print
	cout << dp[n];
	return 0;
}

//int dp[10'001][4] = { 0, };
//int arr[10'001] = { 0, };

//int main()
//{
//	//1. Get input value
//	ios::sync_with_stdio(0), cin.tie(0);
//
//	int n; cin >> n;
//	for (int i = 1; i <= n; ++i)
//	{
//		cin >> arr[i];
//	}
//
//	//2. Set initial value
//	dp[1][1] = dp[1][0] = 0;
//	dp[1][2] = dp[1][3] = arr[1];
//
//	for (int i = 2; i <= n; ++i)
//	{
//		dp[i][0] = max(dp[i - 1][2], dp[i - 1][3]);
//		dp[i][1] = dp[i - 1][0];
//		dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + arr[i];
//		dp[i][3] = dp[i - 1][2] + arr[i];
//	}
//
//	//3. Print
//	cout << max(max(dp[n][0], dp[n][1]), max(dp[n][2], dp[n][3]));
//	return 0;
//}