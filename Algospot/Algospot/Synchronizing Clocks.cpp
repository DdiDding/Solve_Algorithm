#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

#define MAX 999999999
using namespace std;

int ret;
int clocks[16];
vector<int> lists[10] = {{0,1,2},{3,7,9,11},{4,10,14,15},{0,4,5,6,7},
{6,7,8,10,12},{0,2,14,15},{3,14,15},{4,5,7,14,15},{1,2,3,4,5},{3,4,5,9,13}};

void Print()
{
	for (auto d : clocks)
	{
		cout << d << " ";
	}
	cout << endl;
}

//idx : ����ġ�� �ε���
//cnt : ����ġ�� ���� ī��Ʈ
void Counting(int idx, int cnt)
{
	//��� �ð谡 12�ø� ����ų �� result �ֽ�ȭ
	if (accumulate(clocks, clocks + 16, 0) == 12 * 16)
	{
		ret = min(ret, cnt);
	}

	//base case
	//ó������ ������ ����ġ���� Ž������ ��
	if (9 < idx) return;

	//step - ���� ����ġ�� 0 ~ 4�� ������.
	for (int i = 0; i < 4; ++i)
	{
		//����ġ�� �ش��ϴ� ��� �ð� �ð� �߰�
		if (0 < i)
		{
			for (auto & d : lists[idx])
			{
				clocks[d] = (clocks[d] + 3) % 12;
				if (clocks[d] == 0) clocks[d] = 12;
			}
		}
		Counting(idx + 1, cnt + i);
	}

	//���������� 9�ð��� �þ���� 9�ð��� �ٽ� ���ش�.
	for (auto & d : lists[idx])
	{
		clocks[d] -= 9;
		if (clocks[d] <= 0) clocks[d] += 12;
	}
	return;
}

int main()
{
	int c; cin >> c;
	while (c--)
	{
		for (int i = 0; i < 16; ++i)
		{
			cin >> clocks[i];
		}

		ret = MAX;
		Counting(0, 0);
		cout << (ret == MAX ? -1 : ret) << '\n';
	}
	return 0;
}


/*
4 * 4������ ��ġ�� 16���� �ð�
12, 3, 6, 9 ���� �ϳ��� ����Ų��.
����ġ 10���� �ְ� ����ġ�� ������ 3�ð��� �����δ�.

���ð踦 12�÷� ������

������ ����� ��, ���� �ϳ��� ������ �´� ���� = ����ȭ ����
�ϴ� ��Ž�غ���.
����ġ �ϳ��� 4�� �������ִ�.(����ġ�� ������ �ʴ°͵� ����)
����ġ�� �� 10���ϱ�
4^10���� ����� ���� ���´�.
??�� ����� �����ϴ�
=��� �����߰�


��ȹ?
����� ������� ����ġ�� ������ 10�̴�. (�ݺ�Ƚ�����ƴ�)
���� ����ġ�� 0,1,2,3 �������� ���� ����ġ�� �Ѿ��.



BASE : ��� �ð谡 12�ø� ����Ų��.

STEP : ����ġ�� ������ �ش� �ð谡 �����δ�.
��� ����ġ�� ������ ��� �ð谡 �����δ�.

BASE	: ��;��� �ݺ����� ���Ѵ�.
RESULT

n�� ����ġ ����


*/