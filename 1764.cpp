#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

unordered_set<string> s;
vector<string> ret;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m; cin >> n >> m;

	//듣
	while (n--)
	{
		string str; cin >> str;
		s.insert(str);
	}

	//보
	while (m--)
	{
		string str; cin >> str;
		if (s.find(str) != s.end()) ret.push_back(str);
	}

	//정렬
	sort(ret.begin(), ret.end(), less<>());

	//Print
	cout << ret.size()<<'\n';
	for (auto & d : ret)cout << d << '\n';

	return 0;
}

/**
듣보명단,

듣 - n명,
보 - m명

듣 을 해시에 저장하고,
보를 find해서 있으면 출력
*/