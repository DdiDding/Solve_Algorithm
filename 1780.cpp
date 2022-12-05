#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> maps;
int ret[3];

//N�� 9��� S�� 0, E�� 8�� ���´�.
void Counting(int yS, int yE, int xS, int xE)
{
	//��� Ÿ���� ������ Ȯ�� (�ڵ����� ��ĭ�϶��� ����ȴ�.
	bool isAllSame = true;
	int std = maps[yS][xS];

	for (int y = yS; y <= yE; ++y)
	{
		for (int x = xS; x <= xE; ++x)
		{
			if (maps[y][x] != std)
			{
				isAllSame = false;
				break;
			}
		}
		if (isAllSame == false) break;
	}
	
	//��� ������ ī����, ����
	if (isAllSame == true)
	{
		ret[maps[yS][xS] + 1] += 1;
		return;
	}
	
	//9����� �迭���� ��͸� ����.
	int divStd = (yE - yS) / 3 + 1;
	for (int y = 0; y < 3; ++y)
	{
		int tempS_y = yS + (divStd * y);
		for (int x = 0; x < 3; ++x)
		{
			int tempS_x = xS + (divStd * x);
			Counting(tempS_y, tempS_y + divStd - 1, tempS_x, tempS_x + divStd - 1);
		}
	}
	return;
}

int main()
{
	//1. Input values
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;

	maps.resize(n + 1);
	for (int y = 0; y < n; ++y)
	{
		maps[y].resize(n + 1);
		for (int x = 0; x < n; ++x)
		{
			int temp; cin >> temp;
			maps[y][x] = temp;
		}
	}
	
	//2. Do Recursive
	Counting(0, n - 1, 0, n - 1);

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