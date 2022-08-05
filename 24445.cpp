#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100'005
#define FRONT q.front()

vector<int> nodes[MAX];
bool isVisit[MAX];
int result[MAX];

queue<int> q;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int N, M, R; cin >> N >> M >> R;

	int temp1, temp2;
	for (int i = 0; i < M; ++i)
	{
		cin >> temp1 >> temp2;
		nodes[temp1].push_back(temp2);
		nodes[temp2].push_back(temp1);
	}

	//�������� �����ϱ�
	for (int i = 1; i <= N; ++i)
	{
		sort(nodes[i].begin(), nodes[i].end(),greater<>());
	}

	q.push(R);
	memset(isVisit, 0, sizeof(bool) * MAX);
	isVisit[R] = true;
	memset(result, 0, sizeof(int) * MAX);
	result[R] = 1;
	int cnt = 1;
	while (q.empty() == false)
	{
		for (const auto & data : nodes[FRONT])
		{
			//�湮�� ��������
			if (isVisit[data] == false)
			{///ť�� �־��
				q.push(data);
				isVisit[data] = true;
				result[data] = ++cnt;
			}
		}
		q.pop();
	}

	for (int i = 1; i <= N; ++i)
	{
		cout << result[i] << "\n";
	}
	return 0;
}