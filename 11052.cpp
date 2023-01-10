#include <bits/stdc++.h>
using namespace std;
int p[10'005] = { 0, };

//n���� ī�带 ���ϱ� ���� �ִ� ��
int solve(int n)
{
	if (n < 1) return p[n];

	int ret = p[n];
	for (int i = 1; i <= n / 2; ++i)
	{
		ret = max(ret, solve(n - i) + solve(i));
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> p[i];
	}

	cout << solve(n);
	return 0;
}

/*
��� 8������ ī��
1��, 2��, ...,n�� �� ����ִ� ī������ ����
���� �ִ��� ���� �����ؼ� ī�� N���� �����Ϸ��� �Ѵ�.

ī�尡 i�� ���Ե� ī������ ������ p[i]���̴�.

solve(1) = p[1]
solve(2) = max(solve(1) + p[1], p[2])
solve(3) = max(solve(2) + p[1], p[3])

3��
3/2 = 1
i = 0 : 3 - 0, 0
i = 1 : 3 - 1, 1

4��
4/2 = 2
i = 0 : 4 - 0, 0
i = 1 : 4 - 1, 1
i = 2 : 4 - 2, 2
*/

//���� Ǯ��
/*
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <map>
#include <stack>
using namespace std;

int DP[1001]{ 0 };

int main()
{
	//1. Get input value
	ios::sync_with_stdio(0), cin.tie(0);

	int N; cin >> N;

	//2. Do loop
	for (int i = 1; i <= N; ++i)
	{
		cin >> DP[i];
		for (int j = 1; j <= i / 2; ++j)
		{
			DP[i] = max(DP[i], DP[j] + DP[i - j]);
		}
	}

	//3. Print
	cout << DP[N];
	return 0;
}
*/