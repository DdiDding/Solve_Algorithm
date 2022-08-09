#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int temp, result = 0;
	for (int i = 1; i <= 8; ++i)
	{
		cin >> temp;

		if (i == temp) ++result;
		else if (9 - i == temp) --result;
	}

	puts((result == 8) ? "ascending" : (result == -8) ? "descending" : "mixed");
	return 0;
}