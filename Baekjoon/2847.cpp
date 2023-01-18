#include <bits/stdc++.h>
using namespace std;
int lev[105];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> lev[i];
	}

	int result = 0;
	for (int i = n - 2; 0 <= i; --i)
	{
		if (lev[i] >= lev[i + 1])
		{
			result += lev[i] - (lev[i + 1] - 1);
			lev[i] = lev[i + 1] - 1;
		}
	}

	cout << result;

	return 0;
}

/*
게임 N 레벨,
레벨 클리어시 점수 획득
온라인 순위
레벨을 난이도 순으로 배치

1만큼 감소하는게 1번

거꾸로 탐색하면서깍ㄲ으면 됨

*/