#include <bits/stdc++.h>
using namespace std;


char m[51][51];

string pre[2]{
	"WBWBWBWB",
	"BWBWBWBW"
};

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int Y, X; cin >> Y >> X;

	for (int i = 1; i <= Y; ++i)
	{
		for (int j = 1; j <= X; ++j)
		{
			cin >> m[j][i];
		}
	}
	
	//��ü ������ ��ǥ
	int result = 90;
	for (int i = 1; i <= Y - 7; ++i)
	{
		for (int j = 1; j <= X - 7; ++j)
		{

			//��� �ݺ�
			for (int t = 0; t < 2; ++t)
			{
				int cnt = 0;
				bool bh = t;

				//cout << (bh ? "������� ���մϴ�." : "������� ���մϴ�.") << endl;
				//���Ϸ��� ��ǥ
				for (int b = 0; b <  8; ++b)
				{
					for (int a = 0; a < 8; ++a)
					{
						//cout << "������ " << pre[bh][a] << "�� �������� " << m[j + b][i + a];
						if (pre[bh][a] != m[j + b][i + a])
						{
							//cout << "�ٸ��Ƿ� ī�����մϴ�." << endl;
							++cnt;
						}
						else
						{
							//cout << "�����Ƿ� �Ѿ�ϴ�." << endl;
						}
					}
					bh = !bh;
				}
				result = min(result, cnt);
			}
		}
	}
	cout << result;
	return 0;
}


/*
m * n�� ����
������ or ������� �������� ĥ����

�߶�  8 * 8ü�������� ���������
����� �ٸ� ����

one index ����

�� ����������
X - 8
Y - 8

8-8

0 1 2 3 4 5 6 7

one Index <= X - 7

X�� 13�̸�
1  <= 13 - 8 = 5

Y�� 10 �̸�
1 <= 10 -8

�� N - 8 * M - 8  N�� M�� �ִ밡 ������ �ᱹ�� N^2

�ߺ��˻� = 7 * 7 = 49

50 * 50 * 49 * 2 (���)

125000 ������ ��������

�Է°��� Y, X��

*/