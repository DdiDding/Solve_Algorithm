#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<string> v;
int i, j;
int main()
{
	//1. �Է¹ޱ�
	ios::sync_with_stdio(0), cin.tie(0);
	int N; cin >> N;
	v.resize(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	//2. �� �ڸ��� ���ϰ� ����
	int alp[27];
	memset(alp, 0, sizeof(int) * 27);

	for (i = 0; i < v.size(); ++i)
	{
		int pow = 1;
		for (j = v[i].size() - 1; 0<= j ; --j)
		{
			alp[v[i][j] - 'A'] += pow;
			pow *= 10;
		}
	}
	sort(alp, alp + 27, greater());

	int result = 0;
	int cnt = 9;
	for (auto data : alp)
	{
		result += data * cnt;
		--cnt;
	}
	cout << result;
	return 0;
}