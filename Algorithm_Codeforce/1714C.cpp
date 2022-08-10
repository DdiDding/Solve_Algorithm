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
	int T; cin >> T;

	int s;
	int list[9] = { 1,2,3,4,5,6,7,8,9 };
	vector<int> q(9,0);
	stack<int> stc;
	for (int i = 0; i < T; ++i)
	{
		cin >> s;
		for (int j = 9; 0 <= j; --j)
		{
			//원값이 클때
			if (s > j)
			{
				s -= j;
				stc.push(j);
			}
			//같을때
			else if (s == j)
			{
				stc.push(j);
				break;
			}
		}

		while (stc.empty() == false)
		{
			cout << stc.top();
			stc.pop();
		}
		cout << "\n";
	}

	return 0;
}