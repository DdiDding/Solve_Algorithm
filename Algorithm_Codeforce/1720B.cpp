#include <iostream>
#include <algorithm>
using namespace std;

int arr[100'000];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int T; cin >> T;
	while (T--)
	{
		int N; cin >> N;
		for (int i = 1; i <= N; ++i)
		{
			cin >> arr[i];
		}
		sort(arr, arr + N + 1);

		cout << arr[N] + arr[N - 1] - arr[1] - arr[2] << "\n";
	}
	return 0;
}d