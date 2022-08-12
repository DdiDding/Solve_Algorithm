#include <iostream>
#include <algorithm>
using namespace std;

int DP[1'000'001];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N; cin >> N;

	for (int i = 2; i <= N; ++i)
	{
		//�־��� ������� �ϴ� ���س��´�.
		DP[i] = DP[i - 1] + 1;
		if (i % 3 == 0) DP[i] = min(DP[i], DP[i / 3] + 1);
		if (i % 2 == 0) DP[i] = min(DP[i], DP[i / 2] + 1);
	}
	cout << DP[N];
	return 0;
}