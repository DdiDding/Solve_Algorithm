#include <bits/stdc++.h>
using namespace std;

int n;
short maps[2190][2190];
int ret[3];

//x,y�� ������ �� ����,�� ��ġ
void Recursive(int yS, int yE, int xS, int xE)
{
	//base case. 1 * 1ĭ�϶� ī���� �� return

	//1.��� �迭�� ���� ���� ������ Ȯ��

	//2.(true) �ش��ϴ� ���� ���� ī����, return

	//3.(false) 9�������� ������, �� �������� Recursive����
}

//N�� 9��� S�� 0, E�� 8�� ���´�.
void Counting(int yS, int xS, int l)
{
	//��� Ÿ���� ������ Ȯ�� (�ڵ����� ��ĭ�϶��� ����ȴ�.
	bool isAllSame = true;
	for (int y = yS; (y < yS + l) && isAllSame; ++y)
	{
		for (int x = xS; (x < xS + l) && isAllSame; ++x)
		{
			if (maps[y][x] != maps[yS][xS])
			{
				isAllSame = false;
			}
		}
	}

	//��� ���ٸ� ī��Ʈ
	if (isAllSame == true)
	{
		++ret[maps[yS][xS] + 1];
		return;
	}
	
	//9����� �迭���� ��͸� ����.
	l /= 3;
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 3; ++x)
		{
			Counting(yS + l * y, xS + l * x, l);
		}
	}
	return;
}

int main()
{
	//1. Input values
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			cin >> maps[y][x];
		}
	}
	
	//2. Do Recursive
	Counting(0, 0, n);

	//3. Print
	for (const auto & d : ret)
	{
		cout << d << "\n";
	}
	return 0;
}

/*
N x N ��ķ� ǥ���Ǵ� ����
�� ĭ���� -1, 0, 1�� ����
��Ģ������ �ڸ���. 

���̰� �������� ������ �״�� ���
�ƴϸ� ���̸� ���� ũ���� ����  9���� �ڸ���, �� �߸� ���̿� ���� 1�� ������ �ݺ� 

int map[n][n] �� ��� ���� ������ ���
�ƴϸ� 9����� �Ѵ�. �׸��� �ٽ� 1�� �ݺ�

-1�θ� ä���� ��, 0���θ� ä���� ��, 1�θ� ä���� �� ���ϱ�

N��3������ �� = 9�� �ڸ��� ���ϴ� ���� ����.

3
9
27

�κй�����


**/