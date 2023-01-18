#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
unordered_set<string> s;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int n; cin >> n;
	while (n--)
	{
		string name, state;
		cin >> name >> state;

		if (state == "enter") s.insert(name);
		if (state == "leave") s.erase(name);
	}

	vector<string> v;
	for (auto d : s) v.push_back(d);
	sort(v.begin(), v.end(), greater<string>());

	for (auto d : v) cout << d << "\n";
}

/**
출입, 퇴근 기록
현재 회사에 있는 모든 사람 구하기

퇴근 기록이 없는사람이 회사에 있는 사람이잖아

//정말 기록순이면 이거 for lange로 돌아서


1'000'000

**/



//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <functional>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0);
//	int n; cin >> n;
//
//	unordered_map<string, string> m;
//	string key, value; 
//	while (n--)
//	{
//		cin >> key >> value;
//		m[key] = value;
//	}
//
//	vector<string> v;
//	for (const auto & data : m)
//	{
//		if (data.second == "enter") v.push_back(data.first);
//	}
//
//	sort(v.begin(), v.end(),greater<string>());
//	for (const auto & data : v)
//	{
//		cout << data << '\n';
//	}
//
//	return 0;
//}