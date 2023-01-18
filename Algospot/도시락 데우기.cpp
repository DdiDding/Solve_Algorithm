#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<pii> d; d.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> d[i].second;
		for (int i = 0; i < n; ++i)
			cin >> d[i].first;

		sort(d.begin(), d.end(), greater<pii>());

		int ret = 0;
		int micro = 0;
		for (auto & data : d)
		{
			micro += data.second;
			ret = max(ret, micro + data.first);
		}

		cout << ret << '\n';
	}

	return 0;
}

/*
여러 종류의 도시락 n개 주문

전제레인지로 한번에 한개를 데울 수 있다.
i번째 도시락을 데우는데 m[i]초가 걸리고 먹는데 e[i]초가 걸린다.

점심을 먹는데걸리는 시간을 최소화하는 계획을 짜려고 한다.
"첫번째 도시락을 데우는 시간 ~ 모든 사람이 도시락을 다 먹어치운 시간"

1 <= n <= 10'000
unsigned int로 할것

무식하게?
n! 인데 2^10'000으로는 불가능

dp?
??이부분 잘 모르겠네

탐욕법?
무슨 아이디어가 있을까
먹는 시간이 오래 걸리는 순으로?
데우는 시간이 오래 걸리는 순으로?

m[i] < m[k]
m[i] + max(e[i], m[k] + e[k])
m[k] + max(e[k], m[i] + e[i])

solve()
{
	1. 내림차순 정렬

	//첫번째 도시락은 데워야하니까
	ret = 현재까지의 최소 시간
	micro = 전자레인지 가 돌아가는 시간
	for(첫번째 도시락 ~ 모든 도시락)
	{
		micro += i번째 도시락 데우는 시간
		ret += max(ret , m[i] + e[i]);
	}
}

*/