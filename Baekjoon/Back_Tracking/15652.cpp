#include <iostream>
using namespace std;
int n, m;
int arr[9];

void Solve(const int & idx, const int & level)
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

	for (int i = idx; i <= n; ++i)
	{
		arr[level] = i;
		Solve(i, level + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	Solve(1, 0);
	return 0;
}