#include <bits / stdc++.h>
using namespace std;

int solution(vector<int> a, vector<bool> signs) {
	int answer = 0;
	for (int i = 0; i < signs.size(); ++i)
	{
		answer += (signs[i] ? a[i] : -a[i]);
	}
	return answer;
}