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
���� N ����,
���� Ŭ����� ���� ȹ��
�¶��� ����
������ ���̵� ������ ��ġ

1��ŭ �����ϴ°� 1��

�Ųٷ� Ž���ϸ鼭�濫���� ��

*/