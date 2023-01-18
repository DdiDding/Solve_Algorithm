#include <iostream>
using namespace std;

int Solve(const int & n)
{
	if (n == 0) return 1;
	return n * Solve(n - 1);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	cout << Solve(n);
	return 0;
}