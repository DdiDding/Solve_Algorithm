#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;
typedef pair<double, int> pdi;

bool cmp(const pdi & a, const pdi & b)
{
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;

}

vector<int> solution(int N, vector<int> stages) {

	vector<int> answer;
	sort(stages.begin(), stages.end());

	pdi p[501];

	int start = 0;
	for (int i = 0; i < stages.size(); ++i)
	{
		if (stages[i] != stages[i + 1] || i + 1 == stages.size())
		{
			cout << stages[i] << "��" << stages[i + 1] << "�� ��� ���" << endl;
			cout << "���������� ���������� ���� Ŭ�������� ���� �÷��̾��� �� : " << i + 1 - start << endl;
			cout << "���������� ������ �÷��̾� �� : " << stages.size() - start << endl;
			p[stages[i]] = make_pair((double)(i + 1 - start) / (stages.size() - start), stages[i]);
			start = i + 1;
		}
		if (N + 1 == stages[i + 1]) break;
	}

	for (int i = 1; i < N + 1; ++i)
	{
		if (p[i].second == 0) p[i].second = i;
	}

	sort(p + 1, p + N + 1, cmp);

	for (int i = 1; i < N + 1; ++i)
	{
		answer.push_back(p[i].second);
	}

	for (auto & d : p)
	{
		cout << d.second << "�� ������ " << d.first << endl;
	}

	return answer;
}

/*
������ : ���������� ���������� ���� Ŭ�������� ���� �÷��̾��� �� / ���������� ������ �÷��̾� ��

1. stages�� �������� ���� �� Ž��
2. ���������� �ٲ�� �������� ������ ����� pair�� ����
3. pair�� �� vector ���� �� ���������� �̾� �� ���

 00033
 01234
l-----l
 11122

 1 = 2 / 5
 2 = 2 / 2

*/