#include <bits/stdc++.h>
using namespace std;

int s[2190][2190];
int ret[3];

void solve(int y, int x, int len)
{
	//���� �� �������� Ȯ��
	int std = s[y][x];
	bool isSame = true;
	for (int i = y; i < y + len && isSame; ++i)
	{
		for (int j = x; j < x + len && isSame; ++j)
		{
			if (std != s[i][j]) isSame = false;
		}
	}

	//������� : ���� �� ������ ��
	if (isSame == true)
	{
		++ret[std + 1];
		return;
	}

	//�ƴ϶�� ���̸� 9���
	int l = len / 3;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			solve(y + l * i, x + l * j, l);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> s[i][j];
		}
	}

	solve(0, 0, n);

	for (const auto & d : ret)
	{
		cout << d << '\n';
	}
	return 0;
}

/*
N * Nĭ�� -1, 0, 1�� �ϳ��� �����ִ�.

���̰� ��� ���� ���� �Ǿ� �ִٸ� ���̸� �״�� ����Ѵ�.
1�� �ƴ� ��쿡�� ���̸� ���� ũ���� ���� 9���� �ڸ��� ���� �ݺ��Ѵ�.

*/


//���� Ǯ��
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
*/
/*
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
*/