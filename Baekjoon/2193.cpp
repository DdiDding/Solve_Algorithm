#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
//dp[n] = n�ڸ����� ��ģ�� �����̴�.
ll dp[91];

ll solve(int n)
{
	//���� ���
	if (n == 1) return 1;
	if (n == 2) return 1;
	if (n == 3) return 2;

	//�޸����̼�
	if (dp[n] != -1) return dp[n];
	
	//Ǯ��
	return dp[n] = solve(n - 1) + solve(n - 2); 
}

int main()
{
	//1. Get input value & initialize dp table
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	memset(dp, -1, sizeof(dp));

	//2. solve and print
	cout << solve(n)<<'\n';
	return 0;
}

/*
0�� 1�θ� �̷���� ���� ���������Ѵ�.
���� Ư���� ������ ���� ���� ��ģ��
0���� �������� �ʴ´�.
1�� �ι� �������� ��Ÿ���� �ʴ´�.
N�ڸ��� ��ģ�� ������ ���Ѵ� 

f(1) = 1 [ 1 ]
f(2) = 1 [ 10 ]
f(3) = 2 [ 100, 101 ]
f(4) = 3 [ 1000, 1001, 1010 ]
f(5) = 5 [ 10000, 10001, 10010, 10100, 10101]
f(6) = 8 ----- n - 1
f(7) = 13 -----n
f(8) = 21 -----n + 1
f(9) = 34
f(10) = 55

��ȭ��

1. f(n) = f(0) + f(1) + ... f(n - 2)
2. f(n + 1) = f(0) + f(1) + ... + f(n - 2) + f(n - 1)
3. f(n + 1) = f(n) + f(n - 1)
4. f(n) = f(n - 1) + f(n - 2)

f(n) =  f(n - 1)�� ����,


*/

//DP
/*
#include <iostream>
#define MAX 91
using namespace std;

long long int dp[MAX][2];
unsigned long long int dp2[MAX][2];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int N; cin >> N;
	dp[1][0] = 0; dp[1][1] = 1;
	dp2[1][0] = 0; dp2[1][1] = 1;

	for (int i = 2; i <= N; ++i)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	cout << dp[N][0] + dp[N][1];
	return 0;
}
*/