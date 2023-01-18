#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int a, b; cin >> a >> b;
	int A[105][105], B[105][105];
	for (int i = 0; i < a; ++i)
	{
		for (int j = 0; j < b; ++j)
		{
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < a; ++i)
	{
		for (int j = 0; j < b; ++j)
		{
			cin >> B[i][j];
		}
	}

	int ret[105][105];
	for (int i = 0; i < a; ++i)
	{
		for (int j = 0; j < b; ++j)
		{
			ret[i][j] = A[i][j] + B[i][j];
		}
	}

	for (int i = 0; i < a; ++i)
	{
		for (int j = 0; j < b; ++j)
		{
			cout << ret[i][j]<<" ";
		}
		cout << '\n';
	}

	return 0;
}