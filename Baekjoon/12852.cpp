#include <iostream>
using namespace std;
int DP[1'000'005][2];

int main()
{
	//1. Get input value
	ios::sync_with_stdio(0), cin.tie(0);
	int N; cin >> N;

	//2. Set initial value
	DP[2][0] = 1; DP[2][1] = 1;
	DP[3][0] = 1; DP[3][1] = 1;
	DP[4][0] = 2; DP[4][1] = 2;

	//3. Do loop
	for (int i = 5; i <= N; ++i)
	{
		// -1의 연산은 언제나 가능하므로 먼저 해준다.
		DP[i][0] = DP[i - 1][0] + 1;
		DP[i][1] = i - 1;

		if (i % 3 == 0 && DP[i][0] > DP[i / 3][0] + 1)
		{
			DP[i][0] = DP[i / 3][0] + 1;
			DP[i][1] = i / 3;
		}
		if (i % 2 == 0 && DP[i][0] > DP[i / 2][0] + 1)
		{
			DP[i][0] = DP[i / 2][0] + 1;
			DP[i][1] = i / 2;
		}
	}

	////////////////////////////////////////////////////////////
	//4. Print [ 문제 부분 ]

	//A. 시간초과 발생 출력
	cout << DP[N][0] << "\n" << N;
	int i = N;
	do
	{
		i = DP[i][1];
		cout << " " << i;
	} while (i != 1);

	cout << "\n";

	//B. 성공 출력
	cout << DP[N][0] << "\n";
	int cur = N;
	while (1)
	{
		cout << cur << " ";
		if (cur == 1) break;
		cur = DP[cur][1];
	}
	return 0;
}