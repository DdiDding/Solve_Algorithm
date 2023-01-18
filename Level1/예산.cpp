#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> d, int budget)
{
	int answer = 0;
	sort(d.begin(), d.end());

	while (answer < d.size() && 0 <= (budget -= d[answer]))
	{
		++answer;
	}

	return answer;
}