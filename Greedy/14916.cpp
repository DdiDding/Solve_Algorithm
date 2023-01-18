#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	
	if (n <= 8 && n % 2 == 0)
	{
		cout << n / 2;
		return 0;
	}

	int ret = 0;
	while (0 < n)
	{
		if (n % 5 == 0)
		{
			cout << n / 5 + ret;
			return 0;
		}
		++ret; n -= 2;
	}
	cout << -1;
	return 0;
}

/*
2원, 5원으로만
최소로 거슬러주기

18이면
5 * 3 ... 3
2 * 1

5 * 2,
2 * 4



*/