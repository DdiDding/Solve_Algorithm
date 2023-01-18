#include <iostream>
using namespace std;
int n, m;
int arr[8];

void Solve(const int & level)
{
	if (level == m)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		arr[level] = i;
		Solve(level + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	Solve(0);

	return 0;
}