#include <iostream>
using namespace std;

//a 시작점, b 거쳐가는 지점, c 도착지점
void hanoi(const int & n, const int & a, const int & b, const int & c)
{
	if (n == 1)
	{
		cout << a << " " << c << "\n";
		return;
	}

	hanoi(n - 1, a, c, b);
	cout << a << " " << c << "\n";
	hanoi(n - 1, b, a, c);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	cout << (1 << n) - 1 << "\n";
	hanoi(n,1,2,3);

	return 0;
}