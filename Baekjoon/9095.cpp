#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

#define MAX 11
int DP[MAX]{ 0,1,2,4 };

int main()
{
	//1. Fill in array DP
	ios::sync_with_stdio(0), cin.tie(0);
	for (int i = 4; i < MAX; ++i)
	{
		DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3];
	}
	
	//2. Print
	int T,N; cin >> T;
	while (T--)
	{
		cin >> N;
		cout << DP[N]<<"\n";
	}

	return 0;
}