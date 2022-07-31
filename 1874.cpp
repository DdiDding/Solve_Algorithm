#include <iostream>
#include <stack>
#include <vector>
#define MAX 100'001
using namespace std;


int main()
{
	int n;
	int i;
	scanf("%d", &n);

	int result[MAX];
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &(result[i]));
	}
	int list[MAX];
	int listIndex = 0;
	for (i = 0; i < n; ++i)
	{
		list[i] = i + 1;
	}

	vector<char> tempResult;

	stack<int> s;
	int std = -1;
	for (int i = 0; i < n; )
	{
		if (std < result[i])
		{
			std = result[i];
			while (listIndex < std)
			{
				//push
				tempResult.push_back('+');
				s.push(list[listIndex]);
				++listIndex;
			}
		}
		else
		{
			//No
			cout << "NO";
			return 0;
		}

		while (s.empty() == false && s.top() == result[i])
		{
			//pop
			tempResult.push_back('-');
			s.pop();
			++i;
		}
	}

	for (int i = 0; i < tempResult.size(); ++i)
	{
		cout << tempResult[i];
		if (i != tempResult.size() - 1) cout << "\n";
	}

	return 0;
}
