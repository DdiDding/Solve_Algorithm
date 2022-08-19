https://www.acmicpc.net/problem/16928

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <stack>
using namespace std;

//[i][0]�� Ÿ���� ������ ��Ÿ���� [i][1]�� �ּ� �ϼ��� ��Ÿ����.
#define SNAKE -3
#define LADDER -1
#define NOT_VISIT 0
int arr[101][2] = { 0, };

int ladder[101] = { 0, };


int BFS()
{
	priority_queue<int> q;
	q.push(1);

	while (q.empty() == false)
	{
		int c = q.top();
		q.pop();

		bool bMoveNormTile = false;
		int turn = arr[c][1] + 1;
		for (int i = 6; 0 < i; --i)
		{
			int n = c + i;
			if (n == 100) return turn;
			
			//���̰ų� �湮�Ǿ����� �н�
			if (arr[n][0] == SNAKE || 1 <= arr[n][1] || 100 < n) continue;

			//��ٸ����
			else if (arr[n][0] == LADDER)
			{
				//�湮ó��
				arr[n][1] = turn; //��ٸ�Ÿ�� 
				arr[ladder[n]][1] = turn; //��ٸ��� �ö� Ÿ��
				//��ٸ��� �ö� Ÿ���� ť�� ����
				q.push(ladder[n]);
			}

			//�Ϲ� Ÿ���̶�� �ֻ����� �ִ밪�� Ÿ�ϸ� �ִ´�.
			else if (bMoveNormTile == false)
			{
				//�湮ó��
				arr[n][1] = turn;
				//ť�� ����, �Ϲ�Ÿ�� �ޱ� ����
				q.push(n);
				bMoveNormTile = true;
			}
		}

		//cout << turn << "��° ���� ��Ȳ" << endl;
		//for (int i = 1; i <= 100; ++i)
		//{
		//	cout << arr[i][1] << "	";
		//	if(i % 10 == 0)cout << endl;
		//}
		//cout << endl;
	}
	return -1;
}

int main()
	ios::sync_with_stdio(0), cin.tie(0);
{

	int N, M; cin >> N >> M;
	int s, e;
	for (int i = 0; i < N; ++i)
	{
		cin >> s >> e;
		arr[s][0] = LADDER;
		ladder[s] = e;
	}

	for (int i = 0; i < M; ++i)
	{
		cin >> s >> e;
		arr[s][0] = SNAKE;
	}

	cout << BFS();
	return 0;
}