#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

map<int, int> m;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N = 10;
	int temp;
	while (N--)
	{
		cin >> temp;
		//�� ã����
		if (m.find((temp % 42)) == m.end())
		{//����
			m.insert({ temp % 42,0 });
		}
	}

	cout << m.size();
	return 0;
}