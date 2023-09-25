#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
	string a = "";

	int idx = 1;
	for (const char& t : s)
	{
		if (t == ' ')
		{
			a += t;
			idx = 1;
			continue;
		}

		if (1 != idx) a += (isdigit(t) == true ? t : tolower(t));
		if (1 == idx) a += (isdigit(t) == true ? t : toupper(t));
		++idx;
	}

	return a;
}