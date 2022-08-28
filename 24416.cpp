#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <unordered_set>
#include <map>
#include <set>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

int fib_s(int n)
{
	if (n == 1 || n == 2) return 1;

	return fib_s(n - 1) + fib_s(n - 2);
}

int cnt = 0;
vector<int> dp;
int fib_d(int n)
{
	if (n == 1 || n == 2) return 1;
	if (dp[n] != -1) return dp[n];

	for (int i = 3; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		++cnt;
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N; cin >> N;
	dp.resize(N + 1, -1);
	dp[1] = dp[2] = 1;
	
	

	cout << fib_s(N) <<" "<< fib_d(N);

	return 0;
}