#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	while (t--)
	{
		priority_queue<int,vector<int>, greater<int>> q;
		int n; cin >> n;
		while (n--)
		{
			int temp; cin >> temp;
			q.push(temp);
		}

		int ret = 0;
		while (2 <= q.size())
		{
			int t1 = q.top(); q.pop();
			int t2 = q.top(); q.pop();
			ret += t1 + t2;
			q.push(t1 + t2);
		}

		cout << ret << '\n';
	}

	return 0;
}

/*
어떤 선택해나가는 문제.
탐욕?

*/