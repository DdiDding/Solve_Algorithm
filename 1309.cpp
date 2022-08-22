#include <iostream>
#define MOD 9901
using namespace std;

unsigned long long int dp[100'001][2];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int N; cin >> N;

	dp[1][0] = 1;
	dp[1][1] = 1;

	for (int i = 2; i <= N; ++i)
	{
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
		dp[i][0] = (dp[i][1] + dp[i - 1][1]) % MOD;
	}

	cout << ((dp[N][1] * 2) + dp[N][0]) % MOD;
	return 0;
}