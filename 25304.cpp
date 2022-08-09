#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int X, N; cin >> X >> N;

	int a, b;
	for (int i = 0; i < N; ++i)
	{
		cin >> a >> b;
		X -= a * b;
	}
	cout << (char*)((X == 0) ? "Yes" : "No");
	return 0;
}