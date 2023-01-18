#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> pre[3] = { {1,2,3,4,5}, {2,1,2,3,2,4,2,5}, {3,3,1,1,2,2,4,4,5,5} };
	int cnt[3] = { 0, };

	for (int i = 0; i < answers.size(); ++i)
	{
		if (answers[i] == pre[0][i % 5]) cnt[0]++;
		if (answers[i] == pre[1][i % 8]) cnt[1]++;
		if (answers[i] == pre[2][i % 10]) cnt[2]++;
	}

	int Max = max(cnt[0], max(cnt[1], cnt[2]));

	for (int i = 0; i < 3; ++i)
	{
		if (Max == cnt[i]) answer.push_back(i + 1);
	}
	return answer;
} 