#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

unordered_set<string> s;
vector<string> ret;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m; cin >> n >> m;

	//��
	while (n--)
	{
		string str; cin >> str;
		s.insert(str);
	}

	//��
	while (m--)
	{
		string str; cin >> str;
		if (s.find(str) != s.end()) ret.push_back(str);
	}

	//����
	sort(ret.begin(), ret.end(), less<>());

	//Print
	cout << ret.size()<<'\n';
	for (auto & d : ret)cout << d << '\n';

	return 0;
}

/**
�躸���,

�� - n��,
�� - m��

�� �� �ؽÿ� �����ϰ�,
���� find�ؼ� ������ ���
*/