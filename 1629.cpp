#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli a,b,c;
lli solve(int b)
{
	if (b == 1) return a % c;

	lli half = solve(b / 2) % c;
	//홀수면
	if (b & 0x1) return (half * half) % c * a % c;
	//짝수면
	return half * half % c;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> a >> b >> c;
	cout << solve(b);
	return 0;
}

/*
A를 B번 곱한 수 알고 싶다.
C로 나누기

10 ^ 4 = 10'000
10 ^ 2 ^ 2 = 100
100 * 100 = 100'00
(10 * 2) * 2

7 * 9 = 63
7 * 4 * 4 + 7


*/

/*
#include <iostream>
typedef long long  int ll;
using namespace std;

ll MOD(const ll & a, const ll & b, const ll & c)
{
	if (b == 1) return a % c;

	ll half = MOD(a, b / 2, c);
	half = half * half % c;
	//b가 홀수
	if (b & 0x1) half = half * a % c;
	return half;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	ll A, B, C; cin >> A >> B >> C;

	cout << MOD(A,B,C);
	return 0;
}
*/