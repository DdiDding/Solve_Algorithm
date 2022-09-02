#include <bits/stdc++.h>
using namespace std;

int main()
{
	map <string, set<string>> m;
	m["a"].insert("a");
	m["a"].insert("b");
	m["a"].insert("d");
	m["a"].insert("e");

	for (auto d : m)
	{
		for (auto e : d.second)
		{
			int a = e;
		}
	}

	return 0;
}
