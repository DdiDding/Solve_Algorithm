#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str = "";
	cin >> str;

	string digit = "";
	string floating = "";
	for (int i = 0; i < str.length() ; ++i)
	{
		if (str[i] == '.')
		{
			digit = str.substr(0, i);
			floating = str.substr(i + 1, str.length() - 1);
			break;
		}
	}
	
	cout << digit << endl;
	cout << floating << endl;

	return 0;
}
