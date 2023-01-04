#include <bits/stdc++.h>
using namespace std;
int dp[46];

//n번째 피보나치 수를 반환한다.
int solve(int n)
{
	//기저사례
	if (n == 0 || n == 1) return n;

	//메모리제이션
	if (dp[n] != -1) return dp[n];

	return dp[n] = solve(n - 1) + solve(n - 2);
}


int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << solve(n) << '\n';
	return 0;
}
/*
점화식
F[n] = 0  (n = 0)
F[n] = 1  (n = 1)
F[n] = F[n-1] + F[n-2]  (2 <= n)
*/