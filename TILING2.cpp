#include <bits/stdc++.h>
using namespace std;
static const int MOD = 1000000007;

int dp[102];
int solve(int n)
{
	//기저 사례
	if (n < 0) return 0;
	if (n == 0) return 1;

	//메모리제이션
	if (dp[n] != -1) return dp[n];

	//결과
	return dp[n] = (solve(n - 1) + solve(n - 2)) % MOD;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		memset(dp, -1, sizeof(dp));
		cout << solve(n) << '\n';
	}
	return 0;
}

/*
2 * n 크기의 사각형 을 2 * 1크기의 사각형으로 채우는 경우의 수

1. 완전 탐색?

//2 * n개의 타일에서 놓을 수 있는 모든 경우의 수를 반환
solve(n)
{
	n이 0이면 return

	1.가로로 한개를 둔다. + solve(n - 1)
	2.세로로 두개를 둔다. + solve(n - 2)

	return 1 + 2
}

f(1) = 1
f(2) = 2
f(3) = 3
f(4) = 5
f(5) = 8
||||
||ㄷ
|ㄷ|
ㄷ||
ㄷㄷ


*/