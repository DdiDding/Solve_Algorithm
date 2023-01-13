#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<pii> d; d.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> d[i].second;
		for (int i = 0; i < n; ++i)
			cin >> d[i].first;

		sort(d.begin(), d.end(), greater<pii>());

		int ret = 0;
		int micro = 0;
		for (auto & data : d)
		{
			micro += data.second;
			ret = max(ret, micro + data.first);
		}

		cout << ret << '\n';
	}

	return 0;
}

/*
���� ������ ���ö� n�� �ֹ�

������������ �ѹ��� �Ѱ��� ���� �� �ִ�.
i��° ���ö��� ����µ� m[i]�ʰ� �ɸ��� �Դµ� e[i]�ʰ� �ɸ���.

������ �Դµ��ɸ��� �ð��� �ּ�ȭ�ϴ� ��ȹ�� ¥���� �Ѵ�.
"ù��° ���ö��� ����� �ð� ~ ��� ����� ���ö��� �� �Ծ�ġ�� �ð�"

1 <= n <= 10'000
unsigned int�� �Ұ�

�����ϰ�?
n! �ε� 2^10'000���δ� �Ұ���

dp?
??�̺κ� �� �𸣰ڳ�

Ž���?
���� ���̵� ������
�Դ� �ð��� ���� �ɸ��� ������?
����� �ð��� ���� �ɸ��� ������?

m[i] < m[k]
m[i] + max(e[i], m[k] + e[k])
m[k] + max(e[k], m[i] + e[i])

solve()
{
	1. �������� ����

	//ù��° ���ö��� �������ϴϱ�
	ret = ��������� �ּ� �ð�
	micro = ���ڷ����� �� ���ư��� �ð�
	for(ù��° ���ö� ~ ��� ���ö�)
	{
		micro += i��° ���ö� ����� �ð�
		ret += max(ret , m[i] + e[i]);
	}
}

*/