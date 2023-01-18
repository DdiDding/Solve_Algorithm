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
���� n��
�ɴµ� 1�� �ҿ�
��� ������ �ڶ� �� �ʴ�
������ ������ �� �ڶ�� ������ �ʴ�

���� ū�ͺ��� �Ѵ�.

*/