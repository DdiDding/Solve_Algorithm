#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

//[0] : start X //[1] : start Y //[2] : ���� ���� //[3] : ����
vector<vector<int>> dcProp;
set<pii> vertices;
vector<pii> tdc;

pii operator+(const pii & p1, const pii & p2)
{
	return { p1.first + p2.first, p1.second + p2.second };
}
pii operator-(const pii & p1, const pii & p2)
{
	return { p1.first - p2.first, p1.second - p2.second };
}

pii moveSet[4] = { {1, 0},{0, -1},{-1, 0}, {0, 1} };
void MakeDC()
{
	//1. �巡�� Ŀ�긦 ������ŭ �����Ѵ�.
	for (const auto & d : dcProp)
	{
		//1.1 0������ ����, �� ��ǥ ����
		pii s = { d[0], d[1] };
		tdc.push_back(s);
		tdc.push_back(s + moveSet[d[2]]);

		//1.2 1�����̻����, �Է� ���� ��ŭ Ŀ�� ����
		for (int i = 1; i <= d[3]; ++i)
		{
			pii e = tdc.back();
			int tempSize = tdc.size();

			//1.2.1 ���� ������ �������� ȸ�� ���� ��ǥ ���
			for (int j = tempSize - 2; 0 <= j ; --j)
			{
				pii t = tdc[j] - e;
				tdc.push_back(e + make_pair(t.second * -1, t.first));
			}
		}

		//���� ����
		for (const auto & d : tdc)
		{
			vertices.insert(d);
		}
		tdc.resize(0);
	}
}

pii checkSet[3] = { {1, 0}, {0, 1}, {1, 1} };
int CheckRect()
{
	int ret = 0;
	//������ �� ������ �˻�
	for (auto & d : vertices)
	{
		bool isRect = true;
		for (int i = 0; i < 3 && isRect; ++i)
		{
			if (vertices.find(d + checkSet[i]) == vertices.end()) isRect = false;
		}
		if (isRect == true) ++ret;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	//1. Input values
	int c; cin >> c;
	dcProp.resize(c);
	for (int i = 0; i < c; ++i)
	{
		dcProp[i].resize(4);
		cin >> dcProp[i][0] >> dcProp[i][1] >> dcProp[i][2] >> dcProp[i][3];
	}

	//2. Do calculate & Print result
	MakeDC();
	cout << CheckRect();
	return 0;
}

/*
[������ ��ǥ ���] (uv��ǥ��)


�� ���� �Ӽ�
1. ���� ��
2. ���� ����
3. ����

Ư¡
1. ���̴� 1�̴�.
2. ���� ������ ��ġ
������	: ���� ������ ����
����		: ù��° ������ �������� ���� ������ �������� �������� �ð�������� 90�� ȸ���� ��ġ

ũ�� 100 * 100 maps (zero-based 0 ~ 100)
�巡�� Ŀ�� N��

�̶� 1*1 ���簢���� �ײ������� �巡�� Ŀ���� �Ϻ��� ����� ���� �� ���Ͽ���

*/