#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

int DP[100'0001];

int main()
{
	//1. Get input
	ios::sync_with_stdio(0), cin.tie(0);
	int N, M; cin >> N >> M;
	cin >> DP[1];

	int temp;
	for (int i = 2; i <= N; ++i)
	{
		cin >> temp;
		DP[i] = DP[i - 1] + temp;
	}

	//2. Do loop [ O(N) ]
	
	int a, b;
	for (int i = 1; i <= M; ++i)
	{
		cin >> a >> b;
		cout << DP[b] - DP[a - 1] << "\n";
	}

	
	return 0;
}