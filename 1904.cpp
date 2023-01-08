#include <bits/stdc++.h>
using namespace std;
static const int MOD = 15746;
static const int MAX = 1'000'000;

int dp[1'000'005];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	memset(dp, -1, sizeof(dp));

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}

	cout << dp[n]<<endl;
	return 0;
}
//탑다운은 스택오버플로우가 난다!!!

/*

2진 수열
타일에는 00 혹은 1 이 쓰여 있다.

N자리수에서 이 타일을 조합하여 만들 수 있는 이진수열의 개수를
구해라.

제한은 없다.

점화식
홀수 : 이전의 0으로 시작 * 2 + 1로 시작 + 1
짝수 : 이전의 0으로 시작 * 2 + 1로 시작

f(1) = 1 =	1

f(2) = 2 =	00, 11

f(3) = 3 =	001, 100, 111

f(4) = 5 =	0000, 0011, "1001, 1100, 1111"

0000

0011
1001
1100

1111

f(5) = 8 = 00001, 00111, 00100, 10000, 10011, 11001, 11111

00001
00100
10000

00111
10011
11001
11100

11111


f(6) = 13 = 000000, 000011, 001100, 001111, 001001, 100001, 100100, 100111, 110000, 110011, 111100, 111001, 111111

5개
000000
000011
001001
001100
001111

8개
100001
100100
110000
100111
110011
111001
111100
111111

f(7) = 21

8개
0000001
0000100
0010000
0000111
0010011
0011001
0011100
0011111

13개
1000000
1000011
1001001
1001100
1100001
1100100
1110000
1001111
1100111
1110011
1111001
1111100
1111111

걍 피보나치임!! ㅅㅂ!!!
f(n) = f(n-1) + f(n-2)?
int solve(int n)
{
	//기저사례
	if (n <= 3)
	{
		return n;
	}

	//메모리제이션
	if (dp[n] != -1) return dp[n];

	//재귀
	return dp[n] = (solve(n - 1) + solve(n - 2)) % MOD;
}


*/