#include <bits/stdc++.h>
using namespace std;
static const int MAX = 999'999;

vector<int> coin;
int dp[100'005];

int main()
{
	//1. get input value
	ios::sync_with_stdio(0), cin.tie(0);
	fill_n(dp, MAX, 10'005);
	int n, k; cin >> n >> k;
	coin.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> coin[i];
		// initialze dp table
		dp[coin[i]] = 1;
	}

	//2. fill in dp table
	for (int i = 1; i <= k; ++i)
	{
		for (auto & d : coin)
		{
			dp[i + d] = min(dp[i + d], dp[i] + 1);
		}
	}

	//3. Print
	cout << (dp[k] == MAX ? -1 : dp[k]);
	return 0;
}

/*
n���� ������ ������ �ִ�.
�ּ��� �������� ��ġ�� ���� k���� �ǵ��� �ϰ� �ʹ�.

���� ���� n, ��ġ k

dp���̺��� 1 ���� ä�������°� �������� ������(���Ҿ�)

coin[2]�̶��

dp[1] = 1 (������ -1
dp[k] = min(dp[k - coin[0], dp[k - coin[1])
*/
