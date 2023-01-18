#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string n; cin >> n;

	string ret = "";
	int cnt = 0;
	for (auto & d : n)
	{
		if (d == 'X')
		{
			if (cnt == 3)
			{
				ret += "AAAA";
				cnt = 0;
			}
			else ++cnt;
		}
		if (d == '.')
		{
			if (cnt == 0) ret += ".";
			else if (cnt == 2)
			{
				ret += "BB.";
				cnt = 0;
			}
			else
			{
				cout << -1; return 0;
			}
		}
	}
	
	if (cnt == 2) ret += "BB";
	else if (cnt != 0)
	{
		cout << -1; 
		return 0;
	}
	cout << ret;
	return 0;
}
