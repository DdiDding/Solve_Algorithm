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
	int A,B,C; cin >> A >> B >> C;
	int max = A < B ? (B < C ? C : B) : (A < C ? C : A);
	if (A == B)
	{
		if (B == C)
		{
			cout << 10'000 + A * 1000;
		}
		else 
		{
			cout << 1'000 + A * 100;
		}
		return 0;
	}
	else if (B == C || A == C)
	{
		cout << 1'000 + C * 100;
	}
	else
	{
		cout << max * 100;
	}
	return 0;
}