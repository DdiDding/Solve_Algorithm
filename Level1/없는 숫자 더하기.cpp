#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> numbers) {
	bool b[10] = { 0, };
	int answer = 0;

	for (const auto & d : numbers)
		b[d] = true;

	for (int i = 1; i < 10; ++i)
		if (b[i] == false) answer += i;

	return answer;
}