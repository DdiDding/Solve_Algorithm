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

/*
부분 수열 (순서 변경 x)
순 증가 = 증가 부분 수열
그 중 가장 긴 길이를 계산해라.

점화식
52436785
11223453


*/

//재귀
