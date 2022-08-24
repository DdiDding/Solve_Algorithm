#include <iostream>
#include <algorithm>

using namespace std;
int dp[100'002][2];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	
	cin >> dp[1][1];

	int temp;
	for (int i = 2; i <= n; ++i)
	{
		cin >> temp;
		dp[i][1] = dp[i - 1][1] < 1 ? temp : dp[i - 1][1] + temp;
		dp[i][0] = max(dp[i - 2][1], dp[i - 1][0]) + temp;
	}

	sort(&(dp[1][1]) + 0, &(dp[1][0]) + ((n * 2) - 1), greater<int>());
	cout << dp[1][1];
	return 0;
}
/*for (int i = 2; i <= n; ++i)

	{
		cin >> temp;
		dp[i][0] = dp[i - 1][0] < 1 ? temp : dp[i - 1][0] + temp;
		dp[i][1] = max(dp[i - 2][0], dp[i - 1][1]) + temp;
	}*/

/*for (int i = 1; i <= n; ++i)
	{
		cout << dp[i][0] << "\t";
	}
	cout << endl;
	for (int i = 1; i <= n; ++i)
	{
		cout<< dp[i][1] << "\t";
	}*/