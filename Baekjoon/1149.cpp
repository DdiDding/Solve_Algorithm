#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

#define MIN(x,y) ((x) < (y) ? x : y)

#define MAX 1001
#define R 0
#define G 1
#define B 2

int DP[MAX][3];
int arr[MAX][3];

int main()
{
	//1. Get input
	ios::sync_with_stdio(0), cin.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> arr[i][j];
		}
	}

	//2. Set inital value
	DP[1][R] += MIN(arr[0][G],arr[0][B]) + arr[1][R];
	DP[1][G] += MIN(arr[0][R],arr[0][B]) + arr[1][G];
	DP[1][B] += MIN(arr[0][R],arr[0][G]) + arr[1][B];


	//3. Loop
	for (int i = 2; i < N; ++i)
	{
		DP[i][R] += MIN(DP[i - 1][G],DP[i - 1][B]) + arr[i][R];
		DP[i][G] += MIN(DP[i - 1][R],DP[i - 1][B]) + arr[i][G];
		DP[i][B] += MIN(DP[i - 1][R],DP[i - 1][G]) + arr[i][B];
	}

	//4. Print
	cout << MIN(MIN(DP[N - 1][R],DP[N - 1][G]),DP[N - 1][B]);
	return 0;
}