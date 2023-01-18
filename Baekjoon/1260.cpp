#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
#define MAX_NODE 1'001
#define MAX_EDGE 10'001
typedef short integer;
using namespace std;

integer N, M, V;

//1.�����ؼ� �׷����� �ִ� ���
//2.�ּ��� ����ؼ� top���� ��͵����� 

priority_queue<integer,vector<integer>,greater<integer>> node[MAX_NODE];
priority_queue<integer,vector<integer>,greater<integer>> node2[MAX_NODE]; 
bool bIsVisit[MAX_NODE]{ false };
bool result = false;
void Dfs(const int & num)
{
	cout << num << ' ';
	bIsVisit[num] = true;
	while (node[num].empty() == false)
	{
		if (bIsVisit[node[num].top()] == false)
		{
			Dfs(node[num].top());
		}
		node[num].pop();
	}
}

queue<integer> q;
void Bfs(const int & num)
{
	cout << num << ' ';
	bIsVisit[num] = true;
	
	while (node2[num].empty() == false)
	{
		//�湮���� �ʾ����� ť�� �߰�
		if (bIsVisit[node2[num].top()] == false)
		{
			q.push(node2[num].top());
			bIsVisit[node2[num].top()] = true;
			node2[num].pop();
		}
	}

	//���� ���� ���� ��� �湮
	while (q.empty() == false)
	{
		cout << q.front() << ' ';
		while (node2[q.front()].empty() == false && q.size() < N)
		{
			if (bIsVisit[node2[q.front()].top()] == false)
			{
				bIsVisit[node2[q.front()].top()] = true;
				q.push(node2[q.front()].top());
			}
			node2[q.front()].pop();
		}
		q.pop();
	}
}

int main()
{
	
	cin >> N >> M >> V;

	integer a, b;
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;
		node[a].push(b);
		node[b].push(a);
		node2[a].push(b);
		node2[b].push(a);
	}

	Dfs(V);
	memset(bIsVisit, 0, MAX_NODE * sizeof(bool));
	cout << "\n";
	Bfs(V);

	return 0;
}