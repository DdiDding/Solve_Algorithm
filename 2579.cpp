#include <iostream>
#define MAX 301
using namespace std;
#define Max(x,y) ((x) < (y) ? y : x)

int stairs[MAX];
int DP[MAX];

int main()
{
	//1. Get input
	ios::sync_with_stdio(0), cin.tie(0);
	int N; cin >> N;

	for (int i = 1; i <= N; ++i)
	{
		cin >> stairs[i];
	}

	//2. Set initial value
	DP[1] = stairs[1];
	DP[2] = stairs[1] + stairs[2];
	DP[3] = Max(stairs[1],stairs[2]) + stairs[3];

	//3. Solve
	for (int i = 0; i <= N; i++)
	{
		DP[i] = Max(DP[i - 2], DP[i - 3] + stairs[i - 1]) + stairs[i];
	}

	//4. Print
	cout << DP[N] << "\n";
}