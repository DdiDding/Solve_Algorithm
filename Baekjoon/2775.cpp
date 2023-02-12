#include <iostream>
using namespace std;

int cnt = 0;
//a층 b호의 사람을 반환
int solve(int a, int b)
{
	++cnt;
	//기저사례
	if (a == 0) return b;

	int ret = 0;
	for (int i = 1; i <= b; ++i)
	{
		ret += solve(a - 1, i);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	

	int t; cin >> t;
	while (t--)
	{
		int a, b; cin >> a >> b;
		cout << solve(a, b) << '\n';
		cout << "카운트" << cnt << '\n';
	}

	return 0;
}

//테스트 케이스
/*

1 5 15 35 70
1 4 10 20 35
1 3 6 10 15
1 2 3 4 5
*/

//완전탐색
/*

a - 1층 b호 까지의 합을 재귀로 구한다.

//a층 b호의 사람을 반환
int solve(int a, int b)
{
	//기저사례
	if(a == 0) return b;

	int ret = 0;
	for(int i = 1; i <= b; ++i)
	{
		ret += solve(a - 1, b);
	}

	return ret;
}
*/

//DP
/*

*/