#include <bits/stdc++.h>
using namespace std;

map <string, set<string>> m;
map <string, int> mm;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;

	int idx;
	string a, b;
	for (const auto & d : report)
	{
		a = d.substr(0, idx = d.find(" "));
		b = d.substr(idx = d.find(" ") + 1);

		m[b].insert(a);
	}

	for (auto d : m)
	{
		//cout<<"�Ű���� "<<d.first<<", ���� Ƚ���� "<<d.second.size()<<endl;
		if (k <= d.second.size())
		{//ó�������� ���� ����� �����Ѵ�.
			for (auto e : d.second)
			{
				++mm[e];
			}
		}
	}

	for (auto d : id_list)
	{
		if (mm[d] == 0) answer.push_back(0);
		else answer.push_back(mm[d]);
	}

	return answer;
}

/*
�Խ��� �ҷ� �̿��� �Ű� ó������� ���Ϸ� �߼�
������ �Ѹ��� ������ ���� �Ű� ������ 1�� ���� �� �ִ�.
�Ű�� �������� ����

k�� �Ű� �� ������ �̿������ϰ� �������� �߼�(����???), �Ű��� ��� �������� ���� ����� ���Ϸ� �߼�

��� �̿��� id_list, �� �̿��ڰ� �Ű��� id���� report, �Ű����Ƚ�� k
"ó����� ������ ���� Ƚ��", ���������̾ƴ� ���� ó�� ������!!

1.���� ���� ������ �˾ƾ���

2.�� ���������� ���� �Ű��ߴ��� ����Ʈ�� �־����

3.�� ���鼭 �� �������� map�� ī������.

4.ī������ ���� id_listŰ�� ������� ���

report�� �ߺ��� ���� �� �ʿ䰡 �ִ�.

report�� ���������� ���鼭
�Ű������, �Ű� ����- size�� �� Ƚ�� (��ġ��!)
map<string, set<string>>

for(auto d : report)
{
	m[�Ű������].insert(�Ű�����);
}

mm
for(auto d : m)
{
	++mm[d.fisrt];
}

�Ű� ���ڵ��� ��Ͽ�
map<string, int>�ϸ� ��
*/