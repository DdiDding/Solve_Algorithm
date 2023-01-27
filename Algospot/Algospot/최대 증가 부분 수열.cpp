#include <bits/stdc++.h>
using namespace std;

int s[505];
vector<int> dp;

void solve(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		if (dp.back() < s[i])
		{
			dp.push_back(s[i]);
		}
		else
		{
			dp[lower_bound(dp.begin(), dp.end(), s[i]) - dp.begin()] = s[i];
		}
	} 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	dp.reserve(505);
	while (t--)
	{
		//1. Get input value & Initialize dp table
		int n; cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> s[i];
		}
		dp.resize(1, -1);

		solve(n);

		cout << dp.size() - 1 << '\n';
	}
	return 0;
}

/*
수열 S,
메모리 dp

solve(int n )

for(i = 1, s[0] 부터 s[n] 까지 탐색)
{
	1. dp마지막 원소보다 탐색중인 원소가 더 클때 [분기]
	if( dp마지막 원소 < s[i] ) 
		1-1. dp에 push_back해준다.
		1-2. lower_bound로 들어갈 자리를 알아내서 그 인덱스에 s[i]를 넣는다.
}
*/

//종만북 재귀
//시간 복잡도 = O(2^n)
/*
#include <bits/stdc++.h>
using namespace std;

//s의 최대 증가 부분 수열을 반환한다.
int solve(const vector<int>& s)
{
	//기저사례
	if (s.empty() == true) return 0;

	//각 자리에서 시작하여 자신 보다 큰 수를 모은 부분 수열을 만든다.
	int ret = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		vector<int> t;
		for (int j = i + 1; j < s.size(); ++j)
		{
			if (s[i] < s[j]) t.push_back(s[j]);
		}

		ret = max(ret, solve(t) + 1);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	while (t--)
	{
		//1. Get input value & Initialize dp table
		int n; cin >> n;
		vector<int> s; s.resize(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> s[i];
		}

		cout << solve(s) << '\n';
	}
	return 0;
}
*/

//내 스타일의 재귀
/*
//s[n]으로 끝나는 최대증가부분 수열의 길이
int solve(int n)
{
	if (n == 0) return 1;

	int ret = 1;
	//s[0] ~ s[n - 1] < s[n] 인
	for (int i = 0; i < n; ++i)
	{
		if (s[i] < s[n]) ret = max(ret, solve(i) + 1);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	while (t--)
	{
		//1. Get input value & Initialize dp table
		int n; cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> s[i];
		}

		cout << solve(n - 1) << '\n';
	}
	return 0;
}
*/

//내 스타일의 DP
//시간 복잡도 : O(n^2)
/*
#include <bits/stdc++.h>
using namespace std;

int s[505];
int dp[505];

//s[n]으로 끝나는 최대증가부분 수열의 길이
int solve(int n)
{
	if (n == 0) return dp[n] = 1;

	if (dp[n] != -1) return dp[n];

	int ret = 1;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] < s[n]) ret = max(ret, (dp[i] = solve(i)) + 1);
	}
	return dp[n] = ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	while (t--)
	{
		//1. Get input value & Initialize dp table
		int n; cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> s[i];
		}
		memset(dp, -1, sizeof(dp));

		int ret = 0;
		for (int i = 0; i < n; ++i)
		{
			ret = max(ret, solve(i));
		}

		cout << ret << '\n';
	}
	return 0;
}
*/