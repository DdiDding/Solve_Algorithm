#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, int m) {
	vector<int> answer;
	int i;
	//최대공약수
	for (i = min(n, m); 1 < i; --i)
	{
		if (n % i == 0 && m % i == 0) break;
	}
	answer.push_back(i);

	//최대공배수
	for (i = max(n, m); ; ++i)
	{
		if (i % n == 0 && i % m == 0) break;
	}
	answer.push_back(i);

	return answer;
}