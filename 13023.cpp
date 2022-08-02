#include <iostream>
#include <vector>
#define MAX 2001
typedef short integer;
using namespace std;

//�ε��� ��ü�� ����� ���� �ǹ��ϸ� vector�� ���� ���ҵ��� ��� ����Ǿ����� ��Ÿ����.
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
	//�湮���� ���� ������ ��尡 ������ �ڷ� ���ư��� ���� �湮Ȯ���� false�� ��������
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