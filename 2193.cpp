#include <iostream>
#define MAX 91
using namespace std;

long long int dp[MAX][2];
unsigned long long int dp2[MAX][2];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int N; cin >> N;
	dp[1][0] = 0; dp[1][1] = 1;
	dp2[1][0] = 0; dp2[1][1] = 1;

	for (int i = 2; i <= N; ++i)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	cout << dp[N][0] + dp[N][1];
	return 0;
}