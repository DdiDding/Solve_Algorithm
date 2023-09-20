#include <iostream>
#include <utility>
#include <vector>
#include <string.h> //memset �Լ�
using namespace std;
typedef pair<int, int> pii;


//����Լ� ����
/*
/////////////////////////////////////////////////////////////////////
//�ʱ� �� ����
/////////////////////////////////////////////////////////////////////
//�л� ��, Ŀ�� ��
int cntStudent;
int cntCouples;

//ģ������ ���� ����
vector<pii> couples;
vector<pii> pickCouple;

//����� ��� ���� �迭
bool picked[12];

//����
int result;

/////////////////////////////////////////////////////////////////////
//��� �Լ�
/////////////////////////////////////////////////////////////////////
void Solve(int idx)
{
	//������� : ��� Ŀ���� ����� ��
	if (pickCouple.size() == cntStudent / 2)
	{
		++result;
		return;
	}

	//����� �ɷ� : idx ����, ���õ� Ŀ���� ������ Ŀ���� �����ϱ�
	//1. ��� ģ�����踦 ���ʴ�� ��ȸ�Ѵ�.
	for (int i = idx; i < couples.size(); ++i)
	{

		//2. Ž���ϴ� Ŀ���� ��� ���õ����� ���ٸ� �����Ѵ�.
		if (picked[couples[i].first] == false && picked[couples[i].second] == false)
		{
			pickCouple.push_back(pii(couples[i].first, couples[i].second));
			picked[couples[i].first] = true;
			picked[couples[i].second] = true;

			//3. ���� Ŀ�� ������ ���� ��� ȣ��
			Solve(i + 1);

			//4. �ٽ� ������� ���ư���
			pickCouple.pop_back();
			picked[couples[i].first] = false;
			picked[couples[i].second] = false;
		}

	}

	//3. ��� Ž���ص� ������ ����
	return;
}

int main()
{
	//0. �׽�Ʈ ���̽� �ݺ�
	int t; cin >> t;
	while (t--)
	{
		//1. �Է� �� ���� & �ʱ� �� �ʱ�ȭ
		cin >> cntStudent >> cntCouples;
		memset(picked, 0, sizeof(picked));

		result = 0;

		couples.clear();
		pickCouple.clear();
		for (int i = 0; i < cntCouples; ++i)
		{
			int x, y; cin >> x >> y;
			couples.push_back(pii(x, y));
		}

		//2. ��� ����
		Solve(0);

		//3. ���� ���
		cout << result << endl;
	}
}
*/

//������ Ǭ Ʋ�� Ǯ��
/*

set<int> friends[11];
bool check[11];

start - ã������ �л�
maxi - �� �л� ��
cnt - ¦�� ����� �ϴ� ��, ¦�� ���������� �����Ͽ� ���� 0�� �ȴ�.

void Self(const int & maxi, int cnt, int & result)
{
	//��� �л��� �� ¦�������� Ȯ��
	if (cnt == 0)
	{
		++result; 
		return;
	}

	//������ �л� ã��
	//Ư¡�� ���� ���� �л��� ã�´ٴ� ���̴�. �߿�!
	//�߰����� ���������� �������ߴ�.
	int start;
	for (int i = 0; i < maxi; ++i)
	{
		if (check[i] == false)
		{
			start = i;
			break;
		}
	}

	//¦�� ����
	for (int i = start + 1; i < maxi; ++i)
	{
		//start�л��� �ƴϰ� ���� ¦�� �������� �ʾҴٸ�
		if (check[i] == false)
		{
			//���� ģ�����
			if (friends[start].find(i) != friends[start].end())
			{
				//¦�� �����ٴ� üũ�� ���ְ�
				check[start] = true;
				check[i] = true;

				//���� �л��� ã�´�.
				Self(maxi, cnt - 1, result);

				check[start] = false;
				check[i] = false;
			}
		}
	}
}

int main()
{
	//1.Input & Init data

	int C; cin >> C;
	while (C--)
	{
		int n, m; cin >> n >> m;

		//ģ�� üũ�ϱ�
		int a, b;
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b;
			friends[a].insert(b);
			friends[b].insert(a);
		}
		
		int result = 0;
		Self(n, n / 2, result);

		cout << result << '\n';

		memset(check, 0, sizeof(check));
		for (auto & d : friends)
		{
			d.clear();
		}
	}

	return 0;
}
*/

/*
��ǳ�� ����.
�л��� �θ� ¦���´�.
ģ���� �л��鳢�� �A���´�.

�׽�Ʈ ���̽��� �� C
�л��Ǽ�, ģ�� ���� ��

��� ����� ������ �� ���� ģ���� �������� ���� ī�����ϸ� �ɰ� ����!

�κй����� �����غ���

0�� �л����� ¦�� �����.
ģ����� ¦�� ���� ���� �л����� �Ѿ��.

�ش� �л����� ¦�� �����.
ģ����� ¦�� ���� ���� �л����� �Ѿ��.

--------------
0�� �л����� ¦�� �����.
¦�� �������� �л��� �̹� ¦�� ���������� Ȯ��
ģ�������� Ȯ��
ģ����� ¦�� ���� �ٽ� ó������ ����

ģ�����踦 ó������ vector<int>�� �迭�� �Ϸ��ߴµ�
�����غ��� �̰� �׷������ٴ� �ٷιٷ� �˻��ؼ� ã�����ִ°� �����Ͱ��Ƽ�
set?

*/
//
//int n;
//bool areFriends[10][10];
//
//int Counting(bool taken[10])
//{
//	//���� ���� ��ȣ�� ã�´�.
//	bool first = -1;
//	for (int i = 0; i < n; ++i)
//	{
//		if (taken[i] == false)
//		{
//			first = i;
//			break;
//		}
//	}
//
//	//���� ��� : ��� �л��� ¦�� ã������ �� ���� ����� ã������ �����Ѵ�.
//	if (first == -1) return 1;
//
//	int ret = 0;
//	//¦���� �л��� �����ϱ�
//	for (int second = first + 1; second < n; ++second)
//	{
//		if (taken[second] == false && areFriends[first][second])
//		{
//			taken[first] = taken[second] = true;
//			ret += Counting(taken);
//			taken[first] = taken[second] = false;
//		}
//	}
//	return ret;
//}
//���� �ݺ���ó�� ���̴µ� ����� ó�����ͳ����� �ݺ��ϴ°Ͱ� �ٸ�����.
