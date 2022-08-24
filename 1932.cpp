#include <iostream>
#include <algorithm>
#define MAX 125250
using namespace std;

int dp[MAX] = {0,};
int arr[MAX] = { 0, };

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int n; cin >> n;
	int N = (n + 1) * n / 2;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
	}
	dp[1] = arr[1];

	int level = 1, std = 1;
	int l, r;
	for (int i = 1; i <= N - n; ++i)
	{
		if (std < i) std += ++level;
		l = i + level;
		r = l + 1;

		dp[l] = max(dp[i] + arr[l], dp[l]);
		dp[r] = max(dp[i] + arr[r], dp[r]);
	}

	int result = 0;
	for (int i = N - n + 1; i <= N; ++i)
	{
		if (result < dp[i]) result = dp[i];
	}

	cout << result;

	return 0;
}

#include <iostream>
int d[510][2], n, i, k, x, y, j, a;
int m(int a, int b) { return a > b ? a : b; }

int main() 
{
	scanf("%d", &n); for (i = 1; i <= n; i++) { k = i % 2; for (j = 1; j <= i; j++) { scanf("%d", &a); y = d[j][k] = m(d[j][!k], d[j - 1][!k]) + a; if (y > x) x = y; } }printf("%d", x); 
}