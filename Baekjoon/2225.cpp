#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <stack>
using namespace std;

int dp[201];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	//3 - 3, 4 - 6, 5- 10, 6 - 15
	int N, K; cin >> N >> K;

	dp[1] = 1;
	dp[2] = N + 1;

	int T = 1;
	int nT = 2;
	for (int i = 3; i < N; ++i)
	{
		T += ++nT;
		dp[i] = i + (dp[2] - 2) * T;
	}
	cout << dp[K];
	return 0;
}