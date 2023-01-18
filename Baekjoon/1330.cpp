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

	int A, B;
	cin >> A >> B;
	puts(B < A?">":A < B? "==" : "<");
	return 0;
}