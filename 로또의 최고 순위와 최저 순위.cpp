#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> l, vector<int> win) {

	vector<int> answer(0, 2);
	int grade[7] = { 6,6,5,4,3,2,1 };
	int c[50] = { 0, };

	for (auto & d : l)
	{
		++c[d];
	}

	int rightCnt = 0;
	for (auto & d : win)
	{
		if (0 < c[d]) ++rightCnt;
	}

	answer.push_back(grade[rightCnt + c[0]]);
	answer.push_back(grade[rightCnt]);

	return answer;
}