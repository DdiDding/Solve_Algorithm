#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int n; cin >> n;
	cout << n / 100 * 78 << " "<< n - ((n / 100 * 20) / 100 * 22);

	return 0;
}

/*
���� ��� : ��� - ����������

���������� : ��ü �ݾ��� 22%

����� 80%�� �����
20%�� 22%�� �������������� ����

*/