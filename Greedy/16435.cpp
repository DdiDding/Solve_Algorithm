#include <bits/stdc++.h>
using namespace std;
int h[1003];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n, l; cin >> n >> l;
	for (int i = 0; i < n; ++i)
	{
		cin >> h[i];
	}
	sort(h, h + n, less<int>());

	for (int i = 0; i < n; ++i)
	{
		if (h[i] <= l) ++l;
		else break;
	}

	cout << l;
	return 0;
}

/*
��� ��
���� ������ ���� + 1
i��° ������ ���̴� h[i]

*/