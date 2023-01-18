#include <bits/stdc++.h>
using namespace std;
int dp[1'000'001];

//������� n�� 1�� �ɼ� �ִ��� ��ȯ�Ѵ�.
//�Һ��� :  1 <= n <= 1'000'000
int ret = 1'000'001;
int solve(int n)
{
	if (n == 1) return 0;

	if (dp[n] != -1) return dp[n];

	int ret = solve(n - 1) + 1;
	if (n % 3 == 0) ret = min(ret, solve(n / 3) + 1);
	if (n % 2 == 0) ret = min(ret, solve(n / 2) + 1);

	return dp[n] = ret;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N; cin >> N;
	memset(dp, -1, sizeof(dp));
	cout<<solve(N);
	return 0;
}
/*
���� X�� ����� �� �ִ� ������ ������
if(x % 3 == 0) x /= 3;
if(x % 2 == 0) x /= 2;
--x;

���� n�� �־����� �� ���� ������ �ּҷ� �̿��Ͽ� 1�� ��������Ѵ�.
�̶��� �ּҰ��� ���ض�.

��ȭ��?
f[n] = 1 (n = 1)
f[n] = f[n] + 1 (2 < n)


*/

//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int DP[1'000'001];
//
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0);
//	int N; cin >> N;
//
//	for (int i = 2; i <= N; ++i)
//	{
//		//�־��� ������� �ϴ� ���س��´�.
//		DP[i] = DP[i - 1] + 1;
//		if (i % 3 == 0) DP[i] = min(DP[i], DP[i / 3] + 1);
//		if (i % 2 == 0) DP[i] = min(DP[i], DP[i / 2] + 1);
//	}
//	cout << DP[N];
//	return 0;
//}


/*
����Ž�� Ǯ��
#include <iostream>
#include <algorithm>
using namespace std;

int DP[1'000'001];

//������� n�� 1�� �ɼ� �ִ��� ��ȯ�Ѵ�.
//�Һ��� :  n <= 1 <= 1'000'000
int ret = 1'000'001;
int solve(int n, int cnt)
{
	if (n == 1) return cnt;

	int ret = 1'000'001;
	if (n % 3 == 0) ret = min(ret, solve(n / 3, cnt + 1));
	if (n % 2 == 0) ret = min(ret, solve(n / 2, cnt + 1));
	ret = min(ret, solve(n - 1, cnt + 1));

	return ret;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N; cin >> N;

	cout<<solve(N, 0);
	return 0;
}

*/