#include <iostream>
#define MOD 1'000'000'000
using namespace std;
long long DP[101][11] = {0,};

int main()
{
	//1. Get input value & Set initial value for DP table
	ios::sync_with_stdio(0), cin.tie(0);
	int N; cin >> N;

	for (int i = 0; i <= 9; ++i)
	{
		DP[1][i] = 1;
	}

	//2. Do Loop
	for (int i = 2; i <= 100; ++i)
	{
		DP[i][0] = DP[i - 1][1];
		for (int j = 1; j <= 9; ++j)
		{
			DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % MOD;
		}
	}

	//3. Print
	long long result = 0;
	for (int i = 1; i <= 9; ++i)
	{
		result += DP[N][i];
	}
	cout << result % MOD;
	return 0;
}