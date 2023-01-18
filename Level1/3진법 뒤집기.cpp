#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
	stack<int> s;
	int answer = 0;

	while (0 < n)
	{
		s.push(n % 3);
		n /= 3;
	}

	int x = 1;
	while (s.empty() == false)
	{
		answer += s.top() * x;
		s.pop();
		x *= 3;
	}

	return answer;
}