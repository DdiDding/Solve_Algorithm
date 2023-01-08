#include <iostream>
using namespace std;

unsigned long long int DP[1001];

int main()
{
	//1. Get input
	ios::sync_with_stdio(0), cin.tie(0);
	int N; cin >> N;

	//2. Set initial value
	DP[1] = 1;
	DP[2] = 2;

	//3. Set All DP with loop
	for (int i = 3; i <= N; ++i)
	{
		//여기서 mod를 해야 양수에서 mod를 하게 된다.
		DP[i] = (DP[i - 1] + DP[i - 2]) % 10'007;
	}

	//4. Print
	cout << DP[N];
	return 0;
}

//탑다운
/*
#include <bits/stdc++.h>
using namespace std;
static const int MOD = 10'007;
int dp[1001];

int solve(int n)
{
	//기저사례
	if (n <= 3)	return n;

	//메모리제이션
	if (dp[n] != -1) return dp[n];

	//재귀
	return dp[n] = (solve(n - 1) + solve(n - 2)) % MOD;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	memset(dp, -1, sizeof(dp));

	cout << solve(n) << endl;
	return 0;
}
*/