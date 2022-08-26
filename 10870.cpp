#include <iostream>
using namespace std;

int Solve(const int & n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return Solve(n - 1) + Solve(n - 2);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N;  cin >> N;
	cout <<Solve(N);
	return 0;
}