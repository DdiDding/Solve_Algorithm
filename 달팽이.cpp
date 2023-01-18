#include <bits/stdc++.h>
using namespace std;
int dp[2002];
int day, m;

void solve(int n, int m)
{
	//장마 기간이 끝났을 때
	if (day < n) return;

	//메모리제이션
	if (dp[m] != -1) return;
	dp[m] = 1;

	solve(n + 1, m + 1);
	solve(n + 1, m + 2);

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	while (t--)
	{
		memset(dp, -1, sizeof(dp));
		cin >> day >> m;

		solve(0, 0);

		int cnt_1 = 0, cnt_over = 0;
		int i = 0;
		for (const auto & d : dp)
		{
			if (d == 1)
			{
				++cnt_1;
				if (m <= i) ++cnt_over;
			}
			++i;
		}

		cout << (double)cnt_over / cnt_1 << '\n';
	}

	return 0;
}

/*
dp[n]
//n일에 올라갈수 있는 m를 저장?
solve(int n, int m)
{
	//장마가 끝났을때


	//메모리제이션
	if(dp[m] != -1) return;

	1.비가올때
	dp[m] = sovle(n, m+2)

	2.맑을때
	dp[m] = sovle(n, m+1)
}

*/