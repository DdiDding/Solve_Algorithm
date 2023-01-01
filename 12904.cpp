#include <bits/stdc++.h>
using namespace std;
string s, t;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> s >> t;

	while(s.size() < t.size())
	{
		if (t.back() == 'A') t.pop_back();
		else if (t.back() == 'B')
		{
			t.pop_back();
			reverse(t.begin(), t.end());
		}
	}

	cout << (s == t ? 1 : 0);

	return 0;
}

/*
¿ÏÅ½µÉµí

*/