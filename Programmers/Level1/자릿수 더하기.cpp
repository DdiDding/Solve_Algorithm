#include <bits/stdc++.h>

using namespace std;
int solution(int n)
{
	int answer = 0;
	do {
		answer += n % 10;
	} while (0 < (n /= 10));
	return answer;
}