#include <iostream>
#define MAX 100'001
#define MOD 1'000'000'009
using namespace std;

int dp[MAX][4];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	
	dp[1][1] = 1; dp[1][2] = 0; dp[1][3] = 0;
	dp[2][1] = 0; dp[2][2] = 1; dp[2][3] = 0;
	dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;

	for (int i = 4; i <= MAX; ++i)
	{
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
	}

	int n;
	while (T--)
	{
		cin >> n;
		cout << ((long long int)dp[n][1] + dp[n][2] + dp[n][3]) % MOD << "\n";
	}
	return 0;
}