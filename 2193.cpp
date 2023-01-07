#include <iostream>
#define MAX 91
using namespace std;

int dp[91];

//점화식 : f(n) = 
int solve(int n)
{
	//기저 사례
	if (n == 1) return 1;
	if (n == 2) return 1;
	if (n == 3) return 2;

	//풀이
	int ret = 0;
	for (int i = 1; i < n - 1; ++i)
	{
		ret += solve(i);
	}
	return ret + 1;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	cout << solve(n);
	return 0;
}

/*
0과 1로만 이루어진 수를 이진수라한다.
이중 특별한 성질을 가진 수를 이친수
0으로 시작하지 않는다.
1이 두번 연속으로 나타나지 않는다.
N자리의 이친수 개수를 구한다 

f(n) = f(0) + f(1) + ... f(n -2)
f(n) = f(n - 1) + f(n - 2)

점화식
f(1) = 1 [ 1 ]
f(2) = 1 [ 10 ]
f(3) = 2 [ 100, 101 ]
f(4) = 3 [ 1000, 1001, 1010 ]
f(5) = 5 [ 10000, 10001, 10010, 10100, 10101]
f(6) = 8
f(7) = 13
f(8) = 21
f(9) = 34
f(10) = 55

f(n) =  f(n - 1)은 못씀,


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