#include <bits/stdc++.h>
using namespace std;

bool solution(string s)
{
	int P = 0, Y = 0;
	bool answer = true;
	for (auto & d : s)
	{
		d = tolower(d);
		if (d == 'p') ++P;
		if (d == 'y') ++Y;
	}

	return P == Y;
}