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
	int A, B, C; cin >> A >> B >> C;
	cout << (A + (B + C) / 60) % 24 << " " << (B + C) % 60;
	return 0;
}