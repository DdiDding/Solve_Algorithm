#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <map>
#include <stack>
using namespace std;
pair<int, int>DP[41];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;

	//Set initialy value for DP table
	DP[0] = make_pair(1, 0);
	DP[1] = make_pair(0, 1);
	DP[2] = make_pair(1, 1);
	DP[3] = make_pair(1, 2);

	//Do loop
	for (int i = 4; i <= 40; ++i)
	{
		DP[i] = make_pair(DP[i - 1].first + DP[i - 2].first, DP[i - 1].second + DP[i - 2].second);
	}

	//Print
	int temp;
	while (T--)
	{
		cin >> temp;
		cout << DP[temp].first << " " << DP[temp].second << "\n";
	}
	return 0;
}