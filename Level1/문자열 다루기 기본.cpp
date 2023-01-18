#include <bits/stdc++.h>
using namespace std;

bool solution(string s) {

	if (s.size() != 4 && s.size() != 6) return false;

	for (const auto & d : s)
		if (d < '0' || '9' < d) return false;

	return true;
}