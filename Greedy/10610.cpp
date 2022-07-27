#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
using namespace std;
typedef int integer;

int main()
{
	string N;
	cin >> N;

	for (const char & data : N)
	{
		cout << atoi(&data) <<endl;
	}

	/*integer tempInt = 0;
	for (const char & data : N)
	{
		tempInt += data - '0';
	}

	if (tempInt % 3 == 0)
	{
		sort(N.begin(), N.end(), greater<>());
		if (N[N.length() - 1] == '0')
		{
			cout << N;
			return 0;
		}
	}
	cout << "-1";*/
	return 0;
}
