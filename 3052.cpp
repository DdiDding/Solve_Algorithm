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
		//못 찾으면
		if (m.find((temp % 42)) == m.end())
		{//삽입
			m.insert({ temp % 42,0 });
		}
	}

	cout << m.size();
	return 0;
}