#include <bits/stdc++.h>
using namespace std;

int dp[30][30];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int n, m; cin >> n >> m;

		for (int i = 1; i <= m; ++i)
		{
			dp[1][i] = i;
		}

		for (int i = 2; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
			}
		}

		cout << dp[n][m]<<'\n';
	}
	return 0;
}

/*

4 ||  6

다리를 한개놓으면

dp[i][j] = 다리 i개로 도착지점 j개일때 최대 놓을 수 있는 개수

dp[1][1] = 1 / dp[1][2] = 2 / dp[1][3] = 3 / dp[1][4] = 4 /
			   dp[2][2] = 1 / dp[2][3] = 3 / dp[2][4] = 6 / dp[2][5] = 10
							/ dp[3][3] = 1 / dp[3][4] = 4

dp[2][3] = dp[1][1] + dp[1][2];
dp[2][4] = dp[1][1] + dp[1][2] + dp[1][3];

*/
