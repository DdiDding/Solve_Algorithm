#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;

int dp[102];
int ret[102];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;

		dp[1] = 1, dp[2] = 2;
		ret[1] = 0; ret[2] = 0;
		for (int i = 3; i <= n; ++i)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
			if (i & 0x1 == 0x1)
			{
				ret[i] = (dp[i - 1] - 1) + (dp[i - 2] - 1);
			}
			else
			{
				ret[i] = (dp[i - 1] - 2) + (dp[i - 2] - 1); 
			}
		}

		cout << ret[n];
	}
	return 0;
}

/*
2 * n ũ���� Ÿ�Ͽ� �¿� ��Ī�� �ƴ� ������� 

//1. ����Ž��?
2^n �Ұ���

//2. dp?


f(1) = 

f(2) = 
��

*/