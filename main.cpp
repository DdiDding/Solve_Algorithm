#include <bits/stdc++.h>
using namespace std;


int result = 0;
void Make(int floor, int start, int total, int max, const vector<int> & num)
{
	//cout << floor << "층, Total : " << total << endl;
	if (floor == 3)
	{
		if (total == 0) ++result;
		return;
	}

	++floor;
	for (int i = start; i < max; ++i)
	{
		Make(floor, i + 1, total + num[i], max, num);
	}
	return;
}

	

int main()
{
	vector<int> number = { -2, 3, 0 , 2, -5 };
	//vector<int> number = { -3, -2, -1, 0, 1, 2, 3 };
	Make(0, 0, 0, number.size(), number);

	cout << "정답 : " << result;

	return 0;
}
