#include <iostream>
using namespace std;
typedef long long int lld;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	lld L, P, V;

	for (int i = 1; true ; ++i)
	{
		cin >> L >> P >> V;
		if (L + P + V == 0) return 0;

		lld a, b;
		a = V / P * L;
		b = L < (V % P) ? L : (V % P);
		cout << "Case " << i << ": " << a + b << "\n";
	}

	return 0;
}