#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int solve(const vector<int>& h)
{
	int ret = 0;
	int n = h.size();

	for (int left = 0; left < n; ++left)
	{
		int height = h[left];

		for (int right = left; right < n; ++right)
		{
			height = min(height, h[right]);
			ret = max(ret, (right - left + 1) * height);
		}
	}
	return ret;
}

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<int> h;
		for (int i = 0; i < n; ++i)
		{
			int temp; cin >> temp;
			h.push_back(temp);
		}

		cout << "´ä : " << solve(h) << endl;
	}

	return 0;
}
/*

*/