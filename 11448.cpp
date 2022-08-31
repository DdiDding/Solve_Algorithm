#include <bits/stdc++.h>
using namespace std;

#define DP(x) if(dp[x] == 0) dp[x] = x * (x + 1) / 2


int dp[1000];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int t; cin >> t;

	while (t--)
	{
		int n; cin >> n;

		bool pass = false;
		int result_1 = 0;
		int result_2 = 0;
		int result_3 = 0;

		for (int i = 1; i < 1000; ++i)
		{
			DP(i);
			result_1 = dp[i];
			if (n < result_1) break;

			for (int j = 1; j < 1000; ++j)
			{
				DP(j);
				result_2 = dp[j];
				if (n < result_1 + result_2) break;

				for (int k = 1; k < 1000; ++k)
				{
					DP(k);
					result_3 = dp[k];
					if (n < result_1 + result_2 + result_3) break;

					if (result_1 + result_2 + result_3 == n)
					{
						pass = true;
						break;
					}
				}
				if (pass == true) break;
			}
			if (pass == true) break;
		}

		cout << (pass ? "1" : "0") << '\n';
	}
	return 0;
}


/*
�ﰢ�� Tn (1 <= n)

�� n�� T�� ���� ������ �ִ�.

Tn = 1 + 2 + ... N = N(N+1)/2

��� �ڿ����� �ִ� 3���� �ﰢ���� ������ ǥ�� �� �� ����

��� �ڿ����� ��Ȯ�� 3���� �ﰢ���� ������ ǥ�� �� �� �ִ��� �ñ�

3���� �ﰢ���� ������ ǥ�� �� �� �ִ��� ������ �Ǵ��ض�


�� Ti ���� ����
dp[i]

n
Recursive(int i, int len)
{
	//3������ ��� �ȵ�
	//���ϴ� �� �̻��̸� �ȵ�
}

1000 = n (n+1)/2
2000 = n (n +1)
2000 =

��Ʈ��ŷ �ȵɰ� ����
1000 * 1000 * 1000
= 1'000'000'000

*/