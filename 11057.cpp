#include <iostream>
#define MOD 10'007
#define ALL 10
using namespace std;
//일차원의 10번째 인덱스는 총합을 의미한다.
long long dp[1001][11] = { 0, };

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N; cin >> N;
	for (int i = 0; i < 10; ++i)
	{
		dp[1][i] = 1;
		dp[1][ALL] += dp[1][i];
	}
	
	for (int i = 2; i <= N; ++i)
	{
		dp[i][ALL] = dp[i][0] = (dp[i - 1][ALL]) % MOD;
		for (int j = 1; j < 10; ++j)
		{
			dp[i][j] = (dp[i][j - 1] - dp[i - 1][j - 1] + MOD) % MOD;
			dp[i][ALL] = (dp[i][ALL] + dp[i][j]) % MOD;
		}
	}
	
	cout << dp[N][ALL]<< endl;

	return 0;
}