#include <bits/stdc++.h>

using namespace std;

bool IsPrime(int n)
{
	if (n % 2 == 0) return n == 2 ? true : false;

	for (int i = 3; i <= sqrt(n); i += 2)
	{
		if (n % i == 0) return false;
	}

	return true;
}

int solution(int n) {
	int answer = 0;

	for (int i = 2; i <= n; ++i)
	{
		if (IsPrime(i) == true) ++answer;
	}

	return answer;
}