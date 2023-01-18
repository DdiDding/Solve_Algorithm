#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) {

	int max_r = 0, t_r;
	int max_c = 0, t_c;
	for (const auto & d : sizes)
	{
		if (d[0] < d[1]) t_r = d[1], t_c = d[0];
		else t_r = d[0], t_c = d[1];

		max_r = max(max_r, t_r);
		max_c = max(max_c, t_c);
	}

	return max_r * max_c;
}

/*
ȸ�翡�� ����� ������ ũ�⸦ ���Ѵ�.
��� ������ ������ �� �ִ� ���� �ּ� ũ��

���μ��� ��� ����, ū�� ���η� ������ ���η� �����ϸ� ������ ������?
ī�带 ������ ���ʹ������� ��� �����Ҷ�, ���� ū ī���� ����� ��� ���°� ����� �� �ִ�.

���?

sizes�� ���� Ž���ϸ鼭 ū���� �߿����� max��, ���� ���� �߿����� max��
O(n) �԰���
*/