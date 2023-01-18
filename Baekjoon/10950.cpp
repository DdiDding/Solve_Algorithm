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
	int T; cin >> T;
	int temp1, temp2;
	for (int i = 0; i < T; ++i)
	{
		cin >> temp1 >> temp2;
		cout << temp1 + temp2<<"\n";
	}
	return 0;
}