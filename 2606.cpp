#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
#define MAX 105

vector<int> computer[MAX];
bool visit[MAX];
int cnt = 0;

queue<int> q;
void BFS(const int & node)
{
	//1. 시작노드 세팅
	q.push(node);
	visit[node] = true;

	//2. 큐에 있는거 꺼내기
	while (q.empty() == false)
	{
		int temp = q.front(); q.pop();
		//2-b.인접노드 큐에 담기
		for (const auto & data : computer[temp])
		{
			if (visit[data] == false)
			{
				q.push(data);
				visit[data] = true;
				++cnt;
			}
		}
	}
}

int main()
{
	//1. input
	ios::sync_with_stdio(0), cin.tie(0);

	int N, E; cin >> N >> E;
	int a, b;
	while (E--)
	{
		cin >> a >> b;
		computer[a].push_back(b);
		computer[b].push_back(a);
	}

	//2. BFS
	BFS(1);

	//3. print
	cout << cnt;
	return 0;
}

