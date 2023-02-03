//https://algospot.com/judge/problem/read/FIX
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int ret = 0;
		for (int i = 1; i <= n; ++i)
		{
			int temp; cin >> temp;
			if (temp == i) ++ret;
		}
		cout << ret << '\n';
	}
	 
	return 0;
}

/*

*/