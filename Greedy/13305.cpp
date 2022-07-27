#include<iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

typedef unsigned long long integer;
int main()
{
	unsigned int cityNum = 0;
	cin >> cityNum;

	/*vector<pair<int, int>>schedule;
	schedule.push_back(make_pair(end, begin));*/

	vector<pair<integer, integer>> city;
	for (unsigned int i = 0; i < cityNum - 1; ++i)
	{
		int temp;
		scanf("%d", &temp);
		city.push_back(make_pair(0, temp));
	}
	getchar();
	for (auto & data : city)
	{
		int temp;
		scanf("%d", &temp);
		data.first = temp;
	}

	integer price = city[0].first;
	integer result = price * city[0].second;

	for (int i = 1; i < cityNum - 1; ++i)
	{
		if (city[i].first < price) price = city[i].first;
		result += price * city[i].second;
	}

	cout << result;
	return 0;
}
