#include <bits/stdc++.h>
using namespace std;
int s[100];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int ret = 0;
	pair<int, int> idx = make_pair(1, 1);
	for (int i = 1; i < 10; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			int temp; cin >> temp;
			if (ret < temp)
			{
				ret = temp;
				idx.first = i; 
				idx.second = j;
			}
		}
	}

	cout << ret << '\n' << idx.first << ' ' << idx.second;
	return 0;
}

