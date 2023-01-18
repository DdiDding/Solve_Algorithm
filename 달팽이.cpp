#include <bits/stdc++.h>
using namespace std;
int dp[2002];
int day, m;

void solve(int n, int m)
{
	//�帶 �Ⱓ�� ������ ��
	if (day < n) return;

	//�޸����̼�
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
//n�Ͽ� �ö󰥼� �ִ� m�� ����?
solve(int n, int m)
{
	//�帶�� ��������


	//�޸����̼�
	if(dp[m] != -1) return;

	1.�񰡿ö�
	dp[m] = sovle(n, m+2)

	2.������
	dp[m] = sovle(n, m+1)
}

*/