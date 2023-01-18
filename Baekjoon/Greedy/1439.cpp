#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string S;
	cin >> S;

	int cnt0 = 0;
	int cnt1 = 0;
	char std = 0;

	for (const char & data : S)
	{
		if (data != std)
		{
			std = data;
			std == '0' ? ++cnt0 : ++cnt1;
		}
	}

	cout << (cnt0 < cnt1 ? cnt0 : cnt1);
	return 0;
}