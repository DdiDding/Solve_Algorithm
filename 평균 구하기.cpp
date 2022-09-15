#include <bits/stdc++.h>
using namespace std;

double solution(vector<int> arr) {
	double answer = 0;
	for (const auto & d : arr)
	{
		answer += d;
	}

	return answer / arr.size();
}