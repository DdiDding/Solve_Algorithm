#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	string n; cin >> n;

	//1.Check One & Zero
	if (n == "0" || n == "1")
	{
		cout << n;
		return 0;
	}

	//2. Calculate n + n
	string ret;
	bool plus = false;
	while (0 < n.size())
	{
		int a = n.back() - '0';
		n.pop_back();

		a = plus ? a + a + 1 : a + a;
		plus = 9 < a ? true : false;

		ret += to_string(a % 10);
	}
	if (plus == true) ret += '1';

	//3. And then ret minus 2
	int k = 0;
	while (true)
	{
		if (k == 0) ret.at(k) -= 2;
		else ret.at(k) -= 1;

		//�����
		if ('0' <= ret.at(k)) break;

		//������ ��
		ret.at(k) += 10;
		++k;
	}

	//3. Print
	if (ret.back() != '0') cout << ret.back();
	for (int i = ret.size() - 2; -1 < i; --i)
	{
		cout << ret.at(i);
	}
	return 0;
}


//#include <stdio.h>
//#include <string.h>
//
//using namespace std;
//
//int l;
//char a[100];
//
//int main() {
//	int i;
//	scanf("%s", &a);
//	l = strlen(a);
//	//0 ~ 2������ ���� �Ȱ���.
//	if (l == 1 && a[0] < '3') printf("%s", a);
//	//�� ������ �κ�
//	else
//	{
//		//���ڿ��� zero based ������ ����
//		l--;
//
//		//���ڿ��� ó������ ������ �ݺ��ϸ� ����ȭ ��.
//		for (i = 0; i <= l; i++)
//		{
//			a[i] -= '0';
//		}
//
//		//��1�� ���� ������ �ؿ��� *2�� ���ֱ� ���ؼ���.
//		//���ڿ��� ������ ������ 1�� ����.
//		a[l]--;
//		//size�� ����
//		i = l;
//
//		//�ڿ������� ó������ ����� ���ö����� Ž���Ѵ�.
//		while (a[i] < 0)
//		{
//			//�����̱⿡ ���� �ڸ����� 10�� �������°�.
//			a[i] += 10;
//			//Ž���ڸ����� ���� �����ְ�, ������ �ڸ��� �����Ѵ�.
//			a[--i]--;
//		}
//
//		//ó������ ������ ���� *2�� ���ش�.
//		for (i = 0; i <= l; i++)
//		{
//			a[i] *= 2;
//		}
//
//		//*2�� �� ������� ���� �ڸ� ������ �÷��� ���� ������ ������ش�.
//		//�߿��Ѱ� index 1������ ����Ѵ�.
//		for (i = l; i >= 1; i--)
//		{
//			if (10 <= a[i])
//			{
//				a[i] -= 10;
//				a[i - 1]++;
//			}
//		}
//
//		//��� ���
//		//���������� ����ϱ� ������ ������ �������ڸ��� �߰��ǵ� �����ߴ����̴�.
//		for (i = 0; i <= l; i++)printf("%d", a[i]);
//	}
//}