#include <string>
#include <vector>

using namespace std;

string solution(string s) {

	bool b = true;
	for (auto & d : s)
	{
		if (d == ' ') b = true;
		else
		{
			d = b ? toupper(d) : tolower(d);
			b = !b;
		}
	}

	return s;
}