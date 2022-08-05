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

	int H, M;
	cin >> H >> M;

	M -= 45;
	if (M < 0)
	{
		M = 60 + M;
		--H;
		if (H < 0)
		{
			H = 24 + H;
		}
	}

	cout << H << " " << M;

	return 0;
}