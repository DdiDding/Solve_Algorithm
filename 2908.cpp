#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string a, b, c = ""; cin >> a >> b;
	for (int i = a.size() - 1; 0 <= i; --i)
	{
		if (c == "")
		{
			if (a[i] == b[i])
			{
				cout << a[i];
				continue;
			}
			a[i] > b[i] ? c = a : c = b;
		}
		cout << c[i];
	}
	return 0;
}
//
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0);
//	string a, b, c; cin >> a >> b;
//	for (int i = a.size() - 1; 0 <= i; --i)
//	{
//		if (a[i] == b[i]) continue;
//
//		a[i] > b[i] ? c = a : c = b;
//		break;
//	}
//
//	for (int i = a.size() - 1; 0 <= i; --i)
//	{
//		cout << c[i];
//	}
//	return 0;
//}

/*
������ ���� ����
���� ũ�⸦ ���ϴ� ����
�� �ڸ� �� �ΰ��� ĥ �ǿ� ��
ũ�Ⱑ ū �� ����
���� �Ųٷ��д´٤�??

734 893
�Ųٷ�
437 398 

���� ���� ���ϱ� ���� ��� ���� 0�� ���� �ȵ�
�׳� �ε��� �Ųٷ� �ϸ� �ɵ�?

�ε��� �񱳳� �Ųٷ� ����Ҷ� �������� ���ڿ��� ������

���ڸ� ���ϱ� size�� �Ȱ���.
for(str.size() -1 ; 0 <= i; --i)
{
�� ū�� �� �ϸ� �ɵ�? 
�� ū�� ������ �����ϰ� 
}

*/