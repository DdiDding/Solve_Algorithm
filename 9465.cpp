#include <bits/stdc++.h>
using namespace std;
#define MAX 100'001

int s[2][MAX];
int dp[2][MAX];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int T; cin >> T;
	while (T--)
	{
		//1. Get input value
		int n; cin >> n;
		for (int y = 0; y <= 1; ++y)
		{
			for (int x = 1; x <= n; ++x)
			{
				cin >> s[y][x];
			}
		}

		//2. Set initial value in DP table
		memset(dp, 0, sizeof(dp));
		dp[0][1] = s[0][1];
		dp[1][1] = s[1][1];

		//3. Fill in DP table
		for (int i = 2; i <= n; ++i)
		{
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + s[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + s[1][i];
		}

		//4. Print
		cout << max(dp[0][n], dp[1][n])<<'\n';
	}

	return 0;
}

/*
��ƼĿ 2n��
��ƼĿ �ϳ��� ���� �����¿��� ��ƼĿ�� ��� �� ��

������ ���� �ִ밡 �ǰ� ��ƼĿ �����

��Ž�� �׷����� �ʰ� 
f(n) = n��°��ƼĿ�� ���� ���� �ִ� ��
����
*/

/*
#include <iostream>
#include <algorithm>

#define MAX 100'001
using namespace std;

int dp[MAX][3];
int arr[2][MAX];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int T; cin >> T;

	while (T--)
	{
		//1. Get input value
		int N; cin >> N;
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				cin >> arr[i][j];
			}
		}

		//2. Set initial value
		dp[1][0] = arr[0][1];
		dp[1][1] = arr[1][1];
		dp[1][2] = 0;

		//3. Do fill DP table
		for (int i = 2; i <= N; ++i)
		{
			dp[i][0] = max(dp[i - 1][2], dp[i - 1][1]) + arr[0][i];
			dp[i][1] = max(dp[i - 1][2], dp[i - 1][0]) + arr[1][i];
			dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]);
		}

		//4. Print
		cout << max(dp[N][0], max(dp[N][1], dp[N][2])) << "\n";
	}

	return 0;
}
*/

/*
ž�ٿ�
//s : one based array
//s[y][x]�� ����� ���� �ִ� ���� ��ȯ
int solve(int y, int x)
{
	//������� : 1��,2�� �϶�
	if (x == 1) return s[y][1];
	if (x == 2) return s[!y][1] + s[y][2];

	//�޸����̼�
	int & ref = dp[y][x];
	if (ref != -1) return ref;

	return ref = max(solve(!y,x - 1), solve(!y, x - 2)) + s[y][x];
}

*/