#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define Weight first
#define Value second

pii arr[101];

int dp[101][100001];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int n, k; cin >> n >> k;

	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i].Weight >> arr[i].Value;
		dp[i][arr[i].Weight] = max(arr[i].Value, dp[i][arr[i].Weight]);
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			if (j < arr[i].Weight)
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i].Weight] + arr[i].Value);
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= k; ++j)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}


	cout << dp[n][k]<<'\n';
	return 0;
}


/*
�ؼ��� ���࿡ �ʿ��ϴٰ� �����ϴ� N���� ����
W�� V�� ��ġ�� ����

V��ŭ ��� �� �ִ�.

�賶�� ���� �� �ִ� ���ǵ��� ��ġ�� �ִ밪

������ �� n
���� ���� k

���� �����ϰ� �����غ���
��� ����Ǽ��� ���� �Ҽ� ����(��Ʈ��ŷ)

	j->
i��		1	2	3	4	5	6	7
6|13						13	13
4|8					8	8	13	13
3|6				6	8	8	13	14
5|12			6	8	12	13	14

dp[i][j] = min (dp[i - 1][j] ,  dp[i - 1][j - arr[i].����] + arr[i].��ġ
*/

