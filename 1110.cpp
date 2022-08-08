#include <iostream>
using namespace std;

#define TENS(x) (x / 10)
#define UNITS(x) (x % 10)

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N,R,cnt = 0; cin >> R;
	N = R;
	do
	{
		N = (UNITS(N) * 10) + ((TENS(N) + UNITS(N)) % 10);
		++cnt;
	} while (R != N);

	cout << cnt;
	return 0;
}