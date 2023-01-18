#include <bits/stdc++.h>
using namespace std;
static const int MOD = 10'007;
int dp[1001];

//점화식 f(n) = f(n - 2) * 2 + f(n - 1)
int solve(int n)
{
	//기저사례
	if (n <= 2)	return dp[n];

	//메모리제이션
	if (dp[n] != -1) return dp[n];

	//재귀
	return dp[n] = (solve(n - 1) + solve(n - 2) * 2) % MOD;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	memset(dp, -1, sizeof(dp));
	dp[0] = 0; dp[1] = 1; dp[2] = 3;

	cout << solve(n) << endl;
	return 0;
}

/*
f(n) = f(n-2) * 2 + f(n - 1)
최적 부분 구조?
f(1) = 1
|

f(2) = 3
||,
ㄷ,
ㅁ

f(3) = 5
|||,
ㅁ|,|ㅁ
ㄷ|,|ㄷ

f(4) = 11

f(5) = 21


|||||
|ㄷ||, ||ㄷ|, |||ㄷ
|ㅁ||, ||ㅁ|, |||ㅁ
|ㅁㅁ,|ㄷㅁ
|ㅁㄷ, |ㄷㄷ

ㄷ|||, 
ㄷㅁ|, ㄷ|ㅁ,
ㄷㄷ|, ㄷ|ㄷ, 

ㅁ|||, 
ㅁㅁ|, ㅁ|ㅁ, 
ㅁㄷ|, ㅁ|ㄷ, 


*/


/*
#include <bits/stdc++.h>
using namespace std;

int DP[1001];

int main()
{
	//1. Set initial value for DP table
	ios::sync_with_stdio(0), cin.tie(0);

	DP[1] = 1;
	DP[2] = 3;
	DP[3] = 5;
	DP[4] = 11;

	//2. Do loop
	for (int i = 5; i <= 1000; ++i)
	{
		DP[i] = (DP[i - 1] + (DP[i - 2] * 2)) % 10007;
	}

	//3. Print
	int N; cin >> N;
	cout << DP[N];

	return 0;
}
*/