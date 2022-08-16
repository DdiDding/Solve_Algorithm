#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string A[2]; cin >> A[0] >> A[1];

	string min[2]{ "","" };
	string max[2]{ "","" };

	for (int i = 0; i < 2; ++i)
	{
		for (char & data : A[i])
		{

			if (data == '6' || data == '5')
			{
				min[i] += "5";
				max[i] += "6";
			}
			else
			{
				min[i] += data;
				max[i] += data;
			}
		}
	}
	
	int iMin = stoi(min[0]) + stoi(min[1]);
	int iMax = stoi(max[0]) + stoi(max[1]);

	cout << iMin << " " << iMax;
	return 0;
}