#include <bits/stdc++.h>
using namespace std;

int s[505];

//n번째 수가 마지막인 수열의 최대 증가 부분 수열을 반환한다.
int solve(int n)
{
	//기저사례
	if (n == 1) return 1;

	//재귀 흐름
	if (s[n - 1] < s[n]) return solve(n - 1) + 1;
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> s[i];
		}

		int ret = 0;
		for (int i = 0; i <= n; ++i)
		{
			ret = max(ret, solve(n));
		}

		cout << ret << '\n';
	}
	return 0;
}

/*
부분 수열 (순서 변경 x)
순 증가 = 증가 부분 수열
그 중 가장 긴 길이를 계산해라.

점화식
f(1) = 1
f(2) = if( s(1) < s(2) )	true	: f(1) + 1
							false	: 1
f(n) = if( s(n - 1) < s(n) ) true : f(n - 1 ) + 1
							 false: 1


*/