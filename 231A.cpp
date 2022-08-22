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
	int n; cin >> n;
	int result = 0;
	int a, b, c;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b >> c;
		if (2 <= (a + b + c)) ++result;
	}
	cout << result;
	return 0;
}