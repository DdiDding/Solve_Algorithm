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

//[i][0]은 타일의 종류를 나타내고 [i][1]은 최소 턴수를 나타낸다.
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
			
			//뱀이거나 방문되었으면 패스
			if (arr[n][0] == SNAKE || 1 <= arr[n][1] || 100 < n) continue;

			//사다리라면
			else if (arr[n][0] == LADDER)
			{
				//방문처리
				arr[n][1] = turn; //사다리타일 
				arr[ladder[n]][1] = turn; //사다리로 올라간 타일
				//사다리로 올라간 타일을 큐에 삽입
				q.push(ladder[n]);
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

		//cout << turn << "번째 턴의 상황" << endl;
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