#include <iostream>
#include <algorithm>
#include <queue>
typedef long long int ll;
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;

	while (T--)
	{
		//1. Get Input value
		priority_queue<ll,vector<ll>,greater<ll>> q;
		int k; cin >> k;
		ll a, b;
		while (k--)
		{
			cin >> a;
			q.push(a);
		}

		//2. Calculate
		ll result = 0;
		while (1 < q.size())
		{
			a = q.top(); q.pop();
			b = q.top(); q.pop();
			result += a + b;
			q.push(a + b);
		}

		cout << result << '\n';
	}
	return 0;
}