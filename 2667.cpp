#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

#define MAX 26

//int visit[MAX][MAX];
//0�̸� ����, 1�̸� ��, 2�� �湮�Ϸ�
int map[MAX][MAX];

int X[4] = { 0, 1, 0, -1 };
int Y[4] = { 1, 0, -1, 0 };

int DFS(const int & y, const int &  x)
{
	//1. ���� ó�� & �湮ó��
	if (map[y][x] != 1) return 0;

	int result = 1;
	map[y][x] = 2;

	//2. �����¿� ���� ��� �湮
	for (int i = 0; i < 4; ++i)
	{
		//���� �湮 ���� ���̸�
		if (map[y + Y[i]][x + X[i]] == 1)
		{
			//DFS����
			result += DFS(y + Y[i], x + X[i]);
		}
	}
	return result;
}

int main()
{
	//1. get input
	int N; cin >> N;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			scanf("%1d", &map[y][x]);
		}
	}

	//2. DFS
	int cnt = 0;
	vector<int> result;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			if (map[y][x] == 1)
			{
				++cnt;
				result.push_back(DFS(y, x));
			}
		}
	}

	//3. print
	cout << cnt << "\n";
	sort(result.begin(), result.end(), less());
	for (const auto & data : result)
	{
		cout << data << "\n";
	}

	return 0;
}