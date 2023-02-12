#include <iostream>
using namespace std;

int cnt = 0;
//a�� bȣ�� ����� ��ȯ
int solve(int a, int b)
{
	++cnt;
	//�������
	if (a == 0) return b;

	int ret = 0;
	for (int i = 1; i <= b; ++i)
	{
		ret += solve(a - 1, i);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	

	int t; cin >> t;
	while (t--)
	{
		int a, b; cin >> a >> b;
		cout << solve(a, b) << '\n';
		cout << "ī��Ʈ" << cnt << '\n';
	}

	return 0;
}

//�׽�Ʈ ���̽�
/*

1 5 15 35 70
1 4 10 20 35
1 3 6 10 15
1 2 3 4 5
*/

//����Ž��
/*

a - 1�� bȣ ������ ���� ��ͷ� ���Ѵ�.

//a�� bȣ�� ����� ��ȯ
int solve(int a, int b)
{
	//�������
	if(a == 0) return b;

	int ret = 0;
	for(int i = 1; i <= b; ++i)
	{
		ret += solve(a - 1, b);
	}

	return ret;
}
*/

//DP
/*

*/