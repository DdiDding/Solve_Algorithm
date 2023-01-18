#include <bits/stdc++.h>
using namespace std;

int solution(int left, int right) {
	int answer = 0;

	for (; left <= right; ++left)
	{
		int cnt = 1;
		for (int i = 2; i <= left; ++i)
		{
			if (left % i == 0) ++cnt;
		}

		answer += (cnt & 0x1 == 0x1) ? -left : left;
	}
	return answer;
}