#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 100'001

priority_queue<int, vector<int>, greater<int>> nodes[MAX];
bool isJoin[MAX];
int result[MAX];

queue<int> bfsQ;
void AddQueue(const int & index)
{
	static int cnt = 1;
	while (nodes[index].empty() == false)
	{
		if (isJoin[nodes[index].top()] == false)
		{
			isJoin[nodes[index].top()] = true;
			result[nodes[index].top()] = ++cnt;
			bfsQ.push(nodes[index].top());
		}
		nodes[index].pop();
	}
}

void BFS(const int & nodeMany, const int & start)
{
	bfsQ.push(start);
	isJoin[start] = true;
	while (bfsQ.empty() == false)
	{
		AddQueue(bfsQ.front()); bfsQ.pop();
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int node, edge, start;
	cin >> node >> edge >> start;
	memset(result, 0, sizeof(int) * node + 1);


	int temp1, temp2;
	for (int i = 1; i <= edge; ++i)
	{
		cin >> temp1 >> temp2;
		nodes[temp1].push(temp2);
		nodes[temp2].push(temp1);
	}
	BFS(node, start);

	
	result[start] = 1;
	for (int i = 1; i <= node; ++i)
	{
		cout << result[i] << " ";
	}
	return 0;
}

//
//#define X first
//#define Y second // pair���� first, second�� �ٿ��� ���� ���ؼ� ���
//
//using namespace std;
//
//int board[502][502] = { {1,1,1,0,1,0,0,0,0,0},
// {1,0,0,0,1,0,0,0,0,0},
// {1,1,1,0,1,0,0,0,0,0},
// {1,1,0,0,1,0,0,0,0,0},
// {0,1,0,0,0,0,0,0,0,0},
// {0,0,0,0,0,0,0,0,0,0},
// {0,0,0,0,0,0,0,0,0,0} }; // 1�� �Ķ� ĭ, 0�� ���� ĭ�� ����
//bool vis[502][502]; // �ش� ĭ�� �湮�ߴ��� ���θ� ����
//
//int n = 7, m = 10; // n = ���� ��, m = ���� ��
//
//int dx[4] = { 1,0,-1,0 };
//int dy[4] = { 0,1,0,-1 }; // �����¿� �� ������ �ǹ�
//
//int PREBFS()
//{
//	queue<pair<int, int> > Q;
//	vis[0][0] = 1; // (0, 0)�� �湮�ߴٰ� ���
//	Q.push({ 0,0 }); // ť�� �������� (0, 0)�� ����.
//
//	while (!Q.empty()) {
//
//		pair<int, int> cur = Q.front(); Q.pop();
//		cout << '(' << cur.X << ", " << cur.Y << ") -> ";
//
//		for (int dir = 0; dir < 4; dir++) { // �����¿� ĭ�� ���캼 ���̴�.
//
//			int nx = cur.X + dx[dir];
//			int ny = cur.Y + dy[dir]; // nx, ny�� dir���� ���� ������ ������ ĭ�� ��ǥ�� ��
//			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue; // ���� ���� ��� �Ѿ
//			if (vis[nx][ny] || board[nx][ny] != 1) continue; // �̹� �湮�� ĭ�̰ų� �Ķ� ĭ�� �ƴ� ���
//			vis[nx][ny] = 1; // (nx, ny)�� �湮�ߴٰ� ���
//			Q.push({ nx,ny });
//		}
//	}
//}
