#include <iostream>
#include <algorithm>
using namespace std;

int DP[1'000'001];

//몇번만에 n이 1이 될수 있는지 반환한다.
//불변식 :  n <= 1 <= 1'000'000
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

/*
정수 X에 사용할 수 있는 연산은 세가지
if(x % 3 == 0) x /= 3;
if(x % 2 == 0) x /= 2;
--x;

정수 n이 주어졌을 때 연산 세개를 최소로 이용하여 1을 만드려고한다.
이때의 최소값을 구해라.

완탐?
1'000'000
부분문제면
하나의 수에서 여러가지 동작이 가능하지만 결국에는 실패할수동 ㅣㅆ음

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
//		//최악의 방법으로 일단 구해놓는다.
//		DP[i] = DP[i - 1] + 1;
//		if (i % 3 == 0) DP[i] = min(DP[i], DP[i / 3] + 1);
//		if (i % 2 == 0) DP[i] = min(DP[i], DP[i / 2] + 1);
//	}
//	cout << DP[N];
//	return 0;
//}