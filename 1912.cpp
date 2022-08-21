#include <iostream>
using namespace std;

int arr[100'001] = { 0, };

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n >> arr[1];
	int max = arr[1];

	int temp;
	for (int i = 2; i <= n; ++i)
	{
		cin >> temp;
		if (arr[i - 1] <= 0) arr[i] = temp;
		else arr[i] = arr[i - 1] + temp;

		if (max < arr[i]) max = arr[i];
	}

	cout << max;

	return 0;
}