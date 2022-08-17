#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <map>
#include <stack>
using namespace std;

int DP[1001]{ 0 };

int main()
{
	//1. Get input value
	ios::sync_with_stdio(0), cin.tie(0);

	int N; cin >> N;

	//2. Do loop
	for (int i = 1; i <= N; ++i)
	{
		cin >> DP[i];
		for (int j = 1; j <= i / 2; ++j)
		{
			DP[i] = max(DP[i], DP[j] + DP[i - j]);
		}
	}

	//3. Print
	cout << DP[N];
	return 0;
}