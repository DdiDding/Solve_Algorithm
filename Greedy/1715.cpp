#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{
	int N;
	cin >> N;

	priority_queue<int, vector<int>,greater<int>> list;
	for (int i = 0; i < N; ++i)
	{
		int temp = 0;
		cin >> temp;
		list.push(temp);
	}

	int result = 0;
	while (list.size() != 1)
	{
		int cardA = list.top();
		list.pop();
		int cardB = list.top();
		list.pop();
		list.push(cardA + cardB);
		result += cardA + cardB;
	}

	cout << result;

	return 0;
}