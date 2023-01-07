#include <bits/stdc++.h>
using namespace std;

int n;
int t[101][101];
int dp[101][101];

int cnt = 0;
//삼각형을 2차원 배열 t로 생각했을 때
//t[y][x]번째에서 내려간 최대 합을 출력한다.
int solve(int y, int x)
{
	cnt++;
	//기저사례 : 맨 밑의 원소면 더 내려갈 수 없으므로 그 값 반환
	if (y + 1 == n) return t[y][x];

	//메모리제이션
	int & ret = dp[y][x];
	if (ret != -1) return ret;
	
	//반환
	return ret = max(solve(y + 1, x), solve(y + 1, x + 1)) + t[y][x];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T; cin >> T;
	while (T--)
	{
		cnt = 0;
		//1. Get input value & initialize dp table
		memset(dp, -1, sizeof(dp));
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				cin >> t[i][j];
			}
		}

		//2. 
		cout << solve(0, 0)<<'\n';
		cout << " / 호출 횟수 : " <<cnt<<'\n';
	}

	return 0;
}
/*

*/