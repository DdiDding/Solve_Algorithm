#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <map>
#include <stack>
using namespace std;

int DP[1001];

int main()
{
	//1. Set initial value for DP table
	ios::sync_with_stdio(0), cin.tie(0);

	DP[1] = 1;
	DP[2] = 3;
	DP[3] = 5;
	DP[4] = 11;

	//2. Do loop
	for (int i = 5; i <= 1000; ++i)
	{
		DP[i] = (DP[i - 1] + (DP[i - 2] * 2)) % 10007;
	}

	//3. Print
	int N; cin >> N;
	cout << DP[N];

	return 0;
}