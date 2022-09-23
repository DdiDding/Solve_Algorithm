#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
	vector<int> answer;
	for (auto & d : arr)
	{
		if (d % divisor == 0) answer.push_back(d);
	}
	if (answer.size() == 0) answer.push_back(-1);
	else sort(answer.begin(), answer.end());
	return answer;
}