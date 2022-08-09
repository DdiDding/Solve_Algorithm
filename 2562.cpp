#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	pair<int, int> max = make_pair(-1, -1);
	for (int i = 1; i <= 9; ++i)
	{
		int temp; cin >> temp;
		if (max.first < temp)
		{
			max.first = temp;
			max.second = i;
		}
	}
	cout << max.first << endl << max.second;
	return 0;
}