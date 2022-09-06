#include <bits/stdc++.h>
using namespace std;

/*
n이 a의 배수이다.
a,n이 1이 아니어야한다.

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

	for (int i = 0; i < n; ++i)
	{

	}

	return 0;
}