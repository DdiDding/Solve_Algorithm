#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
	int st1 = 0, st2 = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		s[i] == '(' ? ++st1 : ++st2;
		if (st1 < st2) return false;
	}

	return st1 == st2 ? true : false;
}