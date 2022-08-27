#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<int> v(122 - 97 + 2 ,-1);

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string S; cin >> S;

	int i = 0;
	for (const char & data : S)
	{
		if (v[(int)data - 97] == -1)
		{
			v[(int)data - 97] = i;
		}
		++i;
	}

	for (int i = 97; i <= 122; ++i)
	{
		cout << v[i - 97] << " ";
	}
	return 0;
}