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

	int A; cin >> A;
	puts(A % 4 == 0 && (A % 100 != 0 || A % 400 == 0) ? "1" : "0");
	return 0;
}