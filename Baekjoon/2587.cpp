#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	vector<int> v;
	int temp = 0;
	while (cin >> temp)
	{
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), less<int>());
	cout << accumulate(v.begin(), v.end(), 0) / v.size() << '\n' << v[v.size() / 2];
	return 0;
}