#include <iostream>
#include <vector>
using namespace std;

int main()
{
	//1. Input
	int n, m; cin >> n >> m;

	vector<int> ret;
	ret.resize(n,0);

	//2. Calculate
	int i, j, k;
	while (m--)
	{
		cin >> i >> j >> k;

		for (int idx = i - 1; idx<= j - 1; ++idx)
		{
			ret[idx] = k;
		}
	}

	//3. Output
	for (auto& temp : ret)
	{
		cout << temp << ' ';
	}

	return 0;
}

/* 1 ~ N���� �ٱ���, 1 ~ N���� ��
 * M����ŭ �ٱ��Ͽ� ���� �ִ´�.
 * 
*/