#include <iostream>
#include <vector>
#define MAX 2001
typedef short integer;
using namespace std;

//인덱스 자체가 노드의 값을 의미하며 vector에 들은 원소들은 어디에 연결되었는지 나타낸다.
vector<integer> node[MAX];
bool bIsVisit[MAX]{ false };

bool result = false;
void Dfs(const int & num, int depth)
{
	if (depth == 4)
	{
		result = true;
		return;
	}
	bIsVisit[num] = true;
	for (const auto & data : node[num])
	{
		if (bIsVisit[data] == false)
		{
			Dfs(data, depth + 1);
		}
	}
	//방문하지 않은 인접한 노드가 없으면 뒤로 돌아가기 전에 방문확인을 false로 돌려놓음
	bIsVisit[num] = false;
}

int main()
{
	integer N, M;
	cin >> N >> M;

	integer a, b;
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	for (int i = 0; i < M; ++i)
	{
		Dfs(i, 0);
		if (result == true)	break;
	}

	cout << result;
	return 0;
}