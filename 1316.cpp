#include <bits/stdc++.h>
using namespace std;

/*
그룹단어 = 문자열에 속한 "같은 종류의 모든 문자가 연속"해서 나타나는 경우만을 말한다.
*/

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	unordered_map<char, int> m; m.reserve(27);
	int n; cin >> n;
	int i, j, cnt = 0;
	string temp;
	bool result;
	for (i = 0; i < n; ++i)
	{
		result = true;
		cin >> temp;

		j = 0;
		for (const auto & data : temp)
		{
			//처음 발견한 문자라면
			if (m.find(data) != m.end())
			{
				//이전 인덱스와 차이가 2 이상일때 실패
				if (2 <= j - m[data])
				{
					result = false;
					break;
				}
			}
			m[data] = j;
			++j;
		}
		if (result == true)  ++cnt;
		m.clear();
	}
	cout << cnt;
	return 0;
}