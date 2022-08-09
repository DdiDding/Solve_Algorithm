#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N; cin >> N;

	int R;
	string str;
	for (int i = 0; i < N; ++i)
	{
		cin >> R;
		cin >> str;
		for (char c : str)
		{
			cout << string(R, c);
		}

		
		cout << "\n";
	}
	return 0;
}

/*for (int j = 0; j < str.length(); ++j)
		{
			for (int k = 0; k < R; ++k)
			{
				cout << str[j];
			}
		}*/