#include <bits/stdc++.h>
using namespace std;

long long solution(long long n) {
	long long answer = 0;
	vector<int> v;

	while (0 < n)
	{
		v.push_back(n % 10);
		n /= 10;
	}
	sort(v.begin(), v.end(), greater<int>());

	for (const auto & d : v)
	{
		answer *= 10;
		answer += d;
	}

	return answer;
}
