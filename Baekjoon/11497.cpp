#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int arr[10'001];
int result[10'001];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T, N; cin >> T;
	while (T--)
	{		
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i];
		}
		sort(arr, arr + N);

		for (int i = 0; i < N; ++i)
		{
			//È¦¼ö¸é
			if ((i & 0x1) == 0x1)
			{
				result[(N - 1) - ((i - 1) / 2)] = arr[i];
			}
			//Â¦¼ö¸é
			else
			{
				result[i / 2] = arr[i];
			}
		}

		int max = abs(result[0] - result[N - 1]);
		for (int i = 1; i < N; ++i)
		{
			if (max < abs(result[i] - result[i - 1])) max = abs(result[i] - result[i - 1]);
		}

		cout << max << "\n";
	}
	return 0;
}