#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> number) {
	int answer = 0;

	int i, j, k;
	for (i = 0; i < number.size(); ++i)
	{
		for (j = i + 1; j < number.size(); ++j)
		{
			for (k = j + 1; k < number.size(); ++k)
			{
				if (number.at(i) + number.at(j) + number.at(k) == 0) ++answer;
			}
		}
	}

	return answer;
}

//이거 재귀 만들어보기