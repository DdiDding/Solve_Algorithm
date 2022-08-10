#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define MAX 100'005

vector<int> v[MAX];
int result[MAX];
bool visit[MAX];

int Cnt = 0;
void DFS(const int & node)
{
	//0.방문했다면 종료
	if (visit[node] == true) return;

	//1. 방문하지 않았으면 방문처리
	visit[node] = true;
	result[node] = ++Cnt;

	//2.주변노드 방문
	for (const auto & data : v[node])
	{
		if (visit[data] == false)
		{
			DFS(data);
		}
	}
	return;
}

int main()
{
	//1. 입력받기
	ios::sync_with_stdio(0), cin.tie(0);
	int N, M, R; cin >> N >> M >> R;

	int a, b;
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	//2. 오름차순 정렬
	for (auto & data : v)
	{
		sort(data.begin(), data.end(), less());
	}

	//3. DFS
	DFS(R);

	//4. Print
	for (int i = 1; i <= N; ++i)
	{
		cout << result[i] << "\n";
	}
	return 0;
}