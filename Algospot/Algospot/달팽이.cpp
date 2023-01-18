#include <bits/stdc++.h>
using namespace std;
double dp[1001][2002];
int day, top;

double solve(int n, int m)
{
	//�帶�� ��������
	if (n == day) return top <= m ? 1.0 : 0.0;

	//�޸����̼�
	double & ret = dp[n][m];
	if (ret != -1.0) return ret;

	return ret = 0.75 * solve(n + 1, m + 2) + 0.25 * solve(n + 1, m + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	cout << showpoint << setprecision(10);
	while (t--)
	{
		for (auto & d : dp)
		{
			for (auto & dd : d)
			{
				dd = -1.0;
			}
		}

		cin >> top >> day;
		cout << solve(0, 0) << '\n';
	}
	return 0;
}

/*
dp[n]
//n�Ͽ� �ö󰥼� �ִ� m�� ����?
//n�ϵ��� �칰�� �ö� �� �ִ� ����� �� ��ȯ
solve(int n, int m)
{
	//�帶�� ��������
	if(n == day) return top <= m ? 1 : 0

	int ret = 0;
	1.�񰡿ö�
	ret += solve(n + 1, m + 2)

	2.������
	ret += solve(n + 1, m + 1)
}

dp[n] = ����?

*/

//����Ž��
/*
#include <bits/stdc++.h>
using namespace std;
int day, top;

double solve(int n, int m)
{
	//�帶�� ��������
	if (n == day) return top <= m ? 1.0 : 0.0;

	return 0.75 * solve(n + 1, m + 2) + 0.25 * solve(n + 1, m + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	cout << showpoint << setprecision(10);
	while (t--)
	{
		cin >> top >> day;
		cout << solve(0, 0) << '\n';
	}

	return 0;
}
*/