#include <iostream>
using namespace std;

#define MOD 1'000'000'009
#define MAX 1'000'001
unsigned long long int dp[1'000'001];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int t, n; cin >> t;

	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i <= MAX; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
	}
	
	while (t--)
	{
		cin >> n;
		cout << dp[n] << "\n";
	}
	
	return 0;
}