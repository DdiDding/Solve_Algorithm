#include <iostream>
#include <queue>

using namespace std;

//[i][0]은 타일의 종류를 나타내고 [i][1]은 최소 턴수를 나타낸다.
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
			
			//방문되었는지 검사
			if (1 <= arr[n][1] || 100 < n) continue;

			//특수 이동이라면
			else if (arr[n][0] == SPECIAL)
			{
				//일단 특수이동 하기 전의 칸 방문처리
				arr[n][1] = turn;

				//특수이동한곳에서 방문했는지 확인
				n = special[n];
				if (1 <= arr[n][1]) continue;

				//사다리로 올라간 칸 방문 처리 후 큐에 삽입
				arr[n][1] = turn; 
				q.push(n);
			}

			//일반 타일이라면 주사위중 최대값인 타일만 넣는다.
			else if (bMoveNormTile == false)
			{
				//방문처리
				arr[n][1] = turn;
				//큐에 삽입, 일반타일 받기 종료
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