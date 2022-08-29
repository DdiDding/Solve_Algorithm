#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;

	unordered_map<string, string> m;
	string key, value; 
	while (n--)
	{
		cin >> key >> value;
		m[key] = value;
	}

	vector<string> v;
	for (const auto & data : m)
	{
		if (data.second == "enter") v.push_back(data.first);
	}

	sort(v.begin(), v.end(),greater<string>());
	for (const auto & data : v)
	{
		cout << data << '\n';
	}	
	
	return 0;
}