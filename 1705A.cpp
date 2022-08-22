#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#define HMAX 1005
int h[HMAX];

int main()
{


	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--)
	{
		//1. get input
		int N, X; cin >> N >> X;
		int NN = 2 * N;
		for (int i = 0; i < NN; ++i)
		{
			cin >> h[i];
		}

		//2. sort
		sort(h, h + NN, less<int>());

		//3. calculate
		bool bIsCan = true;
		for (int i = 0; i < N; ++i)
		{
			//3-b. 요구한 최소 차이보다 작으면
			if (h[i + N] - h[i] < X)
			{
				bIsCan = false;
				break;
			}
		}

		cout << (string)(bIsCan? "YES\n" : "NO\n");
	}
	return 0;
}