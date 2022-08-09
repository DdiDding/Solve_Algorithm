#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int T; cin >> T;
	string str;
	for (int i = 0; i < T; ++i)
	{
		int result = 0;
		int grade = 0;
		cin >> str;
		for (char c : str)
		{
			if (c == 'O') ++grade;
			else grade = 0;
			result += grade;
		}
		cout << result << "\n";
	}

	return 0;
}