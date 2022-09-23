#include <bits/stdc++.h>
using namespace std;

long long solution(int a, int b) {
	long long n = abs(b - a) + 1;
	long long answer = (a + b) * (n / 2);
	if (n & 0x1 == 0x1) answer += (a + b) / 2;
	cout << answer;
	return answer;
}