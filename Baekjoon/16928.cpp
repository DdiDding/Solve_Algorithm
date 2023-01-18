#include <iostream>
#include <queue>

using namespace std;

//[i][0]�� Ÿ���� ������ ��Ÿ���� [i][1]�� �ּ� �ϼ��� ��Ÿ����.
#define SPECIAL -1
#define NOT_VISIT 0

int arr[101][2] = { 0, };
int special[101] = { 0, };


int BFS()
{
	queue<int> q;
	q.push(1);

	while (q.empty() == false)
	{
		int c = q.front();
		q.pop();

		bool bMoveNormTile = false;
		int turn = arr[c][1] + 1;
		for (int i = 6; 0 < i; --i)
		{
			int n = c + i;
			if (n == 100) return turn;
			
			//�湮�Ǿ����� �˻�
			if (1 <= arr[n][1] || 100 < n) continue;

			//Ư�� �̵��̶��
			else if (arr[n][0] == SPECIAL)
			{
				//�ϴ� Ư���̵� �ϱ� ���� ĭ �湮ó��
				arr[n][1] = turn;

				//Ư���̵��Ѱ����� �湮�ߴ��� Ȯ��
				n = special[n];
				if (1 <= arr[n][1]) continue;

				//��ٸ��� �ö� ĭ �湮 ó�� �� ť�� ����
				arr[n][1] = turn; 
				q.push(n);
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
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int N, M; cin >> N >> M;
	int s, e;
	for (int i = 0; i < N + M; ++i)
	{
		cin >> s >> e;
		arr[s][0] = SPECIAL;
		special[s] = e;
	}

	cout << BFS();
	return 0;
}