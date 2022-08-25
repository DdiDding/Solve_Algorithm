#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1002];
vector<int> two;

int main()
{
	//1. Get input value
	ios::sync_with_stdio(0), cin.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	//2. Find the multiplication of all elements.
	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
		{
			two.push_back(arr[i] + arr[j]);
		}
	}
	sort(arr, arr + N);
	sort(two.begin(), two.end());

	for (int i = N - 1; 0 < i; --i)
	{
		for (int j = i - 1; 0 <= j; --j)
		{
			if (binary_search(two.begin(), two.end(), arr[i] - arr[j]) == true)
			{
				cout << arr[i];
				return 0;
			}
		}
	}

	return 0;
}