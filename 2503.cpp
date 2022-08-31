#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define Strike first
#define Ball second

pii Check(string t, string ask)
{
	int cnt_s = 0;
	int cnt_b = 0;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (t[i] == ask[j])
			{
				if (i == j) ++cnt_s;
				if (i != j) ++cnt_b;
				break;
			}
		}
	}
	return { cnt_s, cnt_b };
}

string ask[101];
pii sb[101];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int answer = 0;
	int n; cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> ask[i] >> sb[i].Strike >> sb[i].Ball;
	}

	string temp;
	pii tsb;
	int i, j;
	for (i = 123; i < 988; ++i)
	{
		temp = to_string(i);
		if (temp[0] == temp[1] || temp[0] == temp[2] || temp[1] == temp[2]) continue;
		if (temp[0] == '0' || temp[1] == '0' || temp[2] == '0') continue;

		for (j = 0; j < n; ++j)
		{
			tsb = Check(temp, ask[j]);
			if (sb[j] != tsb) break;
		}
		if (j == n) ++answer;
	}
	cout << answer;
	return 0;
}

/*
���ھ߱�����
���δٸ� �� �ڸ� ��
���� ����,������ �ڸ��� ��ġ�ϸ� ��Ʈ����ũ + 1
���� ����,�ٸ� �ڸ��� �� + 1

1 2 3 4 5 6 7 8 9
o o o
    o o o
  o o       o
      o       o o

1,2,3,4,5,7

100���� ����
123
12

Ȯ���� �ƴѰų�, �´°� ã�Ƽ� �� �������� ����Ǽ� ã��?

���� �´ٰ� ������ ����� ������
������ input�� �´� �����Ͽ�
=>���ڵ�=>
������ ��� ������ �´� ����� �Ǿ����

����ġ��?
123 ~ 999 �ȿ� �����°� �Ҹ�

�뷫 900��
900 * 100�� = 90'000 �԰�������
*/