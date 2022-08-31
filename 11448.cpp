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
삼각수 Tn (1 <= n)

이 n과 T에 대한 공식이 있다.

Tn = 1 + 2 + ... N = N(N+1)/2

모든 자연수가 최대 3개의 삼각수의 합으로 표현 될 수 있음

몇몇 자연수가 정확히 3개의 삼각수의 합으로 표현 될 수 있는지 궁금

3개의 삼각수의 합으로 표현 될 수 있는지 없는지 판단해라


각 Ti 개수 저장
dp[i]

n
Recursive(int i, int len)
{
	//3개보다 길면 안됨
	//원하는 수 이상이면 안됨
}

1000 = n (n+1)/2
2000 = n (n +1)
2000 =

백트래킹 안될거 같음
1000 * 1000 * 1000
= 1'000'000'000

*/