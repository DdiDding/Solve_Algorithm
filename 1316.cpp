#include <bits/stdc++.h>
using namespace std;

/*
�׷�ܾ� = ���ڿ��� ���� "���� ������ ��� ���ڰ� ����"�ؼ� ��Ÿ���� ��츸�� ���Ѵ�.
*/

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	unordered_map<char, int> m; m.reserve(27);
	int n; cin >> n;
	int i, j, cnt = 0;
	string temp;
	bool result;
	for (i = 0; i < n; ++i)
	{
		result = true;
		cin >> temp;

		j = 0;
		for (const auto & data : temp)
		{
			//ó�� �߰��� ���ڶ��
			if (m.find(data) != m.end())
			{
				//���� �ε����� ���̰� 2 �̻��϶� ����
				if (2 <= j - m[data])
				{
					result = false;
					break;
				}
			}
			m[data] = j;
			++j;
		}
		if (result == true)  ++cnt;
		m.clear();
	}
	cout << cnt;
	return 0;
}