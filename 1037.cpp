#include <bits/stdc++.h>
using namespace std;

/*
n�� a�� ����̴�.
a,n�� 1�� �ƴϾ���Ѵ�.

*/
int arr[51];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n, greater<int>());

	arr[0] *= 2;
	for (int i = 1; i < n; ++i)
	{
		if (1 <= arr[0] % arr[i])
		{
			i = -1;
			arr[0] *= 2;
			continue;
		}
	}

	cout << arr[0];
	return 0;
}