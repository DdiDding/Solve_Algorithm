#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

unordered_map<string,string> dogam;


int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		string str; cin >> str;
		dogam.insert({ str, to_string(i) });
		dogam.insert({ to_string(i), str });
	}

	while (m--)
	{
		string str; cin >> str;
		cout << dogam.find(str)->second << '\n';
	}

	return 0;
}

/***
������ ���ϵǾ� �ִ� ���ϸ��� ���� N, ����� �ϴ� ���� ���� M
1 <= N,M <= 100'000

���ϸ� ��ȣ 1������ N�������� ���ϸ��� �Է����� ���´�.
�׸��� ������ �̾ �Է����� ���´�.

���ϸ� ��ȣ => �̸� ���
���ϸ� �̸� => ��ȣ ���

best�� string�����ϰ� �ε����� ���ϸ� ��ȣ�� ���
�ƴϸ� �ΰ��� ����?
string����, ��ȣ�� ����

�ٵ� �̸����� ��ȣ���� �� ����?
�����ϰԴ�:?
*/