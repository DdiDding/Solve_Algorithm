#include <bits/stdc++.h>
using namespace std;
int tree[100'005];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> tree[i];
	}
	sort(tree, tree + n, greater<int>());

	int ret = 0;
	int day = 0;
	for (int i = 0; i < n; ++i)
	{
		++day;
		ret = max(ret, day + tree[i]);
	}

	cout << ret + 1;

	return 0;
}
/*
묘목 n개
심는데 1일 소요
모든 나무가 자란 후 초대
마지막 나무가 다 자라고 다음날 초대

제일 큰것부터 한다.

*/