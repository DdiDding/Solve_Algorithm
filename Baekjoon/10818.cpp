#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

vector<int>v;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	v.resize(T);
	for (int i = 0; i < T; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end(), less<int>());
	cout << v.front() << " " << v.back();
	return 0;
}