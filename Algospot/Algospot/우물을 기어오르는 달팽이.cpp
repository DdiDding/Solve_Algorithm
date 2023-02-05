#include <bits/stdc++.h>
using namespace std;
int dp[2002];
int day, top;

int solve(int n, int m)
{
	//장마가 끝났을때
	if (n == day) return top <= m ? 1 : 0; 

	return solve(n + 1, m + 2) + solve(n + 1, m + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	cout << showpoint << setprecision(10);
	while (t--)
	{
		memset(dp, -1, sizeof(dp));
		cin >> top >> day;
		cout << solve(0, 0) << endl;
		cout << solve(0, 0) / pow<double>(2, day) << '\n';
	}

	return 0;
}

/*
dp[n]
//n일에 올라갈수 있는 m를 저장?
//n일동안 우물을 올라갈 수 있는 경우의 수 반환
solve(int n, int m)
{
	//장마가 끝났을때
	if(n == day) return top <= m ? 1 : 0

	int ret = 0;
	1.비가올때
	ret += solve(n + 1, m + 2)

	2.맑을때
	ret += solve(n + 1, m + 1)
}

dp[n] = 개수?

*/