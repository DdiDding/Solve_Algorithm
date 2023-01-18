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

	int X, Y; cin >> X >> Y;
	if (0 < X)
	{
		if (0 < Y) cout << 1;
		else cout << 4;
	}
	else
	{
		if (0 < Y) cout << 2;
		else cout << 3;
	}
	return 0;
}