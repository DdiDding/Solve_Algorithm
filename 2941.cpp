#include <bits/stdc++.h>
using namespace std;
string t[8] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string s; cin >> s;

	int i;
	for (auto &d : t)
	{
		while ((i = s.find(d)) != string::npos)
		{
			s.replace(i, d.size(), "#");
		}
	}
	cout << s.size();
	return 0;
}