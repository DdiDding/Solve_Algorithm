#include <iostream>
typedef long long  int ll;
using namespace std;

ll MOD(const ll & a, const ll & b, const ll & c)
{
	if (b == 1) return a % c;

	ll half = MOD(a, b / 2, c);
	half = half * half % c;
	//b°¡ È¦¼ö
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