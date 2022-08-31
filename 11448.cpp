#include <bits/stdc++.h>
using namespace std;
#define MAX 50

int dp[MAX];
bool b[125000];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int t; cin >> t;

	for (int i = 1; i < MAX; ++i)
	{
		dp[i] = i * (i + 1) / 2;
	}
	
	for (int i = 1; i < MAX; ++i)
	{
		for (int j = 1; j < MAX; ++j)
		{
			for (int k = 1; k < MAX; ++k)
			{
				b[dp[i] + dp[j] + dp[k]] = true;
			}
		}
	}

	while (t--)
	{
		int n; cin >> n;
		cout << b[n] << '\n';
	}
	return 0;
}


/*
�ﰢ�� Tn (1 <= n)

�� n�� T�� ���� ������ �ִ�.

Tn = 1 + 2 + ... N = N(N+1)/2

��� �ڿ����� �ִ� 3���� �ﰢ���� ������ ǥ�� �� �� ����

��� �ڿ����� ��Ȯ�� 3���� �ﰢ���� ������ ǥ�� �� �� �ִ��� �ñ�

3���� �ﰢ���� ������ ǥ�� �� �� �ִ��� ������ �Ǵ��ض�


�� Ti ���� ����
dp[i]

n
Recursive(int i, int len)
{
	//3������ ��� �ȵ�
	//���ϴ� �� �̻��̸� �ȵ�
}

1000 = n (n+1)/2
2000 = n (n +1)
2000 =

��Ʈ��ŷ �ȵɰ� ����
1000 * 1000 * 1000
= 1'000'000'000

100 * 100 ==10000

50 * 50 = 2500

*/