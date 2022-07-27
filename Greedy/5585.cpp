#include<iostream>
using namespace std;

int main()
{
	int N, result = 0;
	cin >> N;
	N = 1000 - N;

	int changes[6]{ 500, 100, 50, 10, 5, 1 };

	for (const auto & data : changes)
	{
		result += N / data;
		N %= data;
	}
	cout << result;
	return 0;
}
