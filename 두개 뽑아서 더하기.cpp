#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> num) {
	vector<int> answer;
	bool check[205] = { 0, };

	int i, j;
	for (i = 0; i < num.size(); ++i)
	{
		for (j = i + 1; j < num.size(); ++j)
		{
			if (check[num[i] + num[j]] == false)
			{
				check[num[i] + num[j]] = true;
				answer.push_back(num[i] + num[j]);
			}
		}
	}

	sort(answer.begin(), answer.end());

	return answer;
}