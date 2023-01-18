#include <bits/stdc++.h>
using namespace std;

int n;
int t[101][101];

int solve(int y, int x)
{
	//������� : �� ���� ���Ҹ� �� ������ �� �����Ƿ� �� �� ��ȯ
	if (y + 1 == n) return t[y][x];
	
	//��ȯ
	return max(solve(y + 1, x), solve(y + 1, x + 1)) + t[y][x];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T; cin >> T;
	while (T--)
	{
		//1. Get input value
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				cin >> t[i][j];
			}
		}

		//2. Sovle and Print
		cout << solve(0, 0)<<'\n';
	}

	return 0;
}
//DP
/*
#include <bits/stdc++.h>
using namespace std;

int n;
int t[101][101];
int dp[101][101];

int cnt = 0;
//�ﰢ���� 2���� �迭 t�� �������� ��
//t[y][x]��°���� ������ �ִ� ���� ����Ѵ�.
int solve(int y, int x)
{
	cnt++;
	//������� : �� ���� ���Ҹ� �� ������ �� �����Ƿ� �� �� ��ȯ
	if (y + 1 == n) return t[y][x];

	//�޸����̼�
	int & ret = dp[y][x];
	if (ret != -1) return ret;

	//��ȯ
	return ret = max(solve(y + 1, x), solve(y + 1, x + 1)) + t[y][x];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T; cin >> T;
	while (T--)
	{
		cnt = 0;
		//1. Get input value & initialize dp table
		memset(dp, -1, sizeof(dp));
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				cin >> t[i][j];
			}
		}

		//2.
		cout << solve(0, 0)<<'\n';
		cout << " / ȣ�� Ƚ�� : " <<cnt<<'\n';
	}

	return 0;
}
*/