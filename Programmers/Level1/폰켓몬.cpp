#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
	int take = nums.size() / 2;
	set<int> s(nums.begin(), nums.end());

	return s.size() < take ? s.size() : take;
}

/*
N������ N/2���� ��������
���� �پ��� ���ϸ� ��������

1. ������ ��ΰ�?
2. ����������� �� ����
*/