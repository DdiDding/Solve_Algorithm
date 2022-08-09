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
	long long int n, m, a; cin >> n >> m >> a;
	long long int x = 0, y = 0;

	x += (n / a) + (n % a == 0 ? 0 : 1);
	y += (m / a) + (m % a == 0 ? 0 : 1);
	
	cout << x * y;
	return 0;
}