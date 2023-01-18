#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int C, N;
double ret;
bool check[10];
double m[10][10];

//idx : ���� �ִ� ����
//temp : �߰� ��� ��
//cnt : �湮�� ����, ó���� 1�� �־� �����Ѵ�.
void Count(int idx, double temp, int cnt)
{
	//���� ���
	if (cnt == N)
	{
		ret = min(ret, temp);
		return;
	}
	
	//1.�湮���� ���� ���� ��� Ž��
	check[idx] = true;
	for (int i = 0; i < N; ++i)
	{
		//1-1. �湮���� ���� ���󿩾��ϰ�, ���糪�� �ƴϾ���Ѵ�.
		if (check[i] == false && i != idx)
		{
			check[i] = true;
			Count(i, temp + m[idx][i], cnt + 1);
			check[i] = false;
		}
	}
	check[idx] = false;
}

int main()
{
	cin >> C;
	while (C--)
	{
		//1. input,init value
		cin >> N;
		ret = 1.7976931348623158e+308;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> m[i][j];
			}
		}

		//2. Calculate
		for (int i = 0; i < N; ++i)
		{
			Count(i, 0.0, 1);
		}
		cout << fixed << setprecision(10);
		cout << ret << endl;
	}
	return 0;
}

/*

����Ž����� , �ð��� O(8!)�� �ð������� ����.
��� ���

�湮�ߴ��� üũ�ؾ���.


*/






//
//
//#include <iostream>
//#include <algorithm>
//#include <limits>
//using namespace std;
//
//int C;
//int N;
//int start;
//double ret = DBL_MAX;
//bool check[10];
//double m[10][10];
//
////idx : ���� �ִ� ����
////temp : �߰� ��� ��
////cnt : �湮�� ���� ī��Ʈ ó���� 1�־ߤ��� 
//void Count(int idx, double temp, int cnt)
//{
//	//���� ���
//	if (cnt == N)
//	{
//		ret = min(ret, temp + m[idx][start]);
//		cout << "�ĺ� �� : " << temp + m[idx][start] << endl;
//		return;
//	}
//
//	check[idx] = true;
//
//	//1.�湮���� ���� ���� ��� Ž��
//	for (int i = 0; i < N; ++i)
//	{
//		//1-1. �湮���� ���� ���󿩾��ϰ�, ���糪�� �ƴϾ���Ѵ�.
//		if (check[i] == false && i != idx)
//		{
//			check[i] = true;
//			cout << idx << "���󿡼� " << i << "����� �̵�" << endl;
//			cout << m[idx][i] << "�� ���� ���� �߰� �� " << temp + m[idx][i] << "�Դϴ�.\n\n";
//			Count(i, temp + m[idx][i], cnt + 1);
//			check[i] = false;
//		}
//	}
//}
//
//int main()
//{
//	cin >> C;
//	while (C--)
//	{
//		//1. input,init value
//		cin >> N;
//		memset(check, 0, sizeof(check));
//		for (int i = 0; i < N; ++i)
//		{
//			for (int j = 0; j < N; ++j)
//			{
//				cin >> m[i][j];
//			}
//		}
//
//		//2.
//		for (int i = 0; i < N; ++i)
//		{
//			Count(i, 0.0, 1);
//		}
//
//		cout << ret << endl;
//	}
//
//	return 0;
//}
//
///*
//
//����Ž����� , �ð��� O(8!)�� �ð������� ����.
//��� ���
//
//�湮�ߴ��� üũ�ؾ���.
//
//
//*/