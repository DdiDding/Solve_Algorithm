#include <bits/stdc++.h>

using namespace std;

string pre[4]{
	"RT","CF","JM","AN"
};

string solution(vector<string> survey, vector<int> choices) {
	string answer = "";

	unordered_map<char, int> m;

	int len = survey.size();
	for (int i = 0; i < len; ++i)
	{
		int c = choices[i];
		//비동의
		if (c < 4)
		{
			m[survey[i][0]] += (4 - c);
		}
		//동의
		if (5 <= c)
		{
			m[survey[i][1]] += (c - 4);
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		if (m[pre[i][0]] < m[pre[i][1]]) answer += pre[i][1];
		else answer += pre[i][0];
	}

	return answer;
}