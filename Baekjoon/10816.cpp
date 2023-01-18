#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 500'002
int arr[MAX];

int Lower_bound(const int & size, const int & f)
{
	int s = 0, e = size, m;
	while (s < e)
	{
		m = (s + e) / 2;

		if (f <= arr[m]) e = m;
		else s = m + 1;
	}

	return s;
}

int Upper_bound(const int & size, const int & f)
{
	int s = 0, e = size, m;
	while (s < e)
	{
		m = (s + e) / 2;

		if (f < arr[m]) e = m;
		else s = m + 1;
	}

	return e;
}


int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	
	int N; cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);

	int M,F; cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> F;
		cout << Upper_bound(N, F) - Lower_bound(N, F) << " ";
	}

	return 0;
}