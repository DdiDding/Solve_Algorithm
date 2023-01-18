#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
	int answer = 0;
	long long num = n;

	while (++answer <= 500)
	{
		if (num == 1) return --answer;
		(num & 0x1 == 0x1) ? num = num * 3 + 1 : num /= 2;
	}
	return -1;
}