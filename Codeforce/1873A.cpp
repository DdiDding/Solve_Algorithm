#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		int cnt_wrong = 0;

		if (s[0] != 'a') ++cnt_wrong;
		if (s[1] != 'b') ++cnt_wrong;
		if (s[2] != 'c') ++cnt_wrong;

		cout << (cnt_wrong == 3 ? "NO" : "YES") << '\n';
	}

	return 0;
}
/*
���ĺ� a,b,c �� �Բ� �� ���� ī�尡 �ִ�.

�� ���� ���� �۾��� ������ �� �ִ�.
o �ΰ��� ī�带 ���� ��ȯ�ϱ�

�۾� �� ������ abc�� �� �� �ֽ��ϱ�? �����ϸ� "YES" �ƴϸ� "NO"�� ��ȯ�ϼ���.

Input.
ù �ٿ��� �׽�Ʈ ���̽��� ������ �� �ڸ����� ������ �ֽ��ϴ�. 
�� �׽�Ʈ ���̽��� �� ���� a,b,c�� ������ ���ڿ��� ����ֽ��ϴ�.
*/