#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1001
int dp[MAX];
int arr[MAX];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N; cin >> N;
	
	cin >> dp[1];
	for (int i = 2; i <= N; ++i)
	{
		cin >> dp[i];
		for (int j = 1; j <= i / 2; ++j)
		{
			dp[i] = min(dp[i], dp[j] + dp[i - j]); 
		}
	}

	cout << dp[N];
	
	return 0;
}