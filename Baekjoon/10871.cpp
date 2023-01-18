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
	int N, X; cin >> N >> X;
	int temp;
	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		if (temp < X) cout << temp << " ";
	}
	return 0;
}