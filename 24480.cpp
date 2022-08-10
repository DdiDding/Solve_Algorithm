#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100005

vector<int> v[MAX];
int result[MAX];
bool bVisit[MAX];

int cnt = 0;
void DFS(const int & node)
{
	//a-1 �湮������� Ȯ��
	if (bVisit[node] == true) return;

	//a-2 �ƴϸ� �湮ó�� �� ��� ����
	bVisit[node] = true;
	result[node] = ++cnt;

	//b ���� ��� �湮
	for (const auto & data : v[node])
	{
		DFS(data);
	}
	return;
}

int main()
{
	//1. �Է¹ޱ�
	ios::sync_with_stdio(0), cin.tie(0);
	int N, M, R; cin >> N >> M >> R;

	int a, b;
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	//2. �����ϱ�
	for (auto & data : v)
	{
		sort(data.begin(), data.end(), greater());
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