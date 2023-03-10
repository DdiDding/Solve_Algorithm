#include <bits/stdc++.h>
using namespace std;
#define MAX 50

int dp[MAX];
bool b[125000];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int t; cin >> t;

	for (int i = 1; i < MAX; ++i)
	{
		dp[i] = i * (i + 1) / 2;
	}
	
	for (int i = 1; i < MAX; ++i)
	{
		for (int j = 1; j < MAX; ++j)
		{
			for (int k = 1; k < MAX; ++k)
			{
				b[dp[i] + dp[j] + dp[k]] = true;
			}
		}
	}

	while (t--)
	{
		int n; cin >> n;
		cout << b[n] << '\n';
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

100 * 100 ==10000

50 * 50 = 2500

*/