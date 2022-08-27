#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[9];

int main()
{
	cin >> n >> m;
	fill_n(arr + m, 9 - m, 1);
	do
	{
		for (int i = 0; i < n; ++i)
		{
			if (arr[i] == 0)
			{
				cout << i + 1 <<" ";
			}
		}
		cout << endl;
	} while (next_permutation(arr, arr + n));
	
	return 0;
}


////idx = 자신이 몇번째인지, level = 깊이
//void Solve(int idx, int level)
//{
//	if (m < level)
//	{
//		for (int i = 1; i <= m; ++i)
//		{
//			cout << arr[i] << ' ';
//		}
//		cout << '\n';
//		return;
//	}
//
//	for (int i = idx + 1; i <= n; ++i)
//	{
//		arr[level] = i;
//		Solve(i, level + 1);
//	}
//}
//
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0);
//	cin >> n >> m;
//	for (int i = 1; i <= n; ++i)
//	{
//		arr[1] = i;
//		Solve(i, 2);
//	}
//	return 0;
//}