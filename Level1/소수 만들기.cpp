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

int solution(vector<int> nums) {
	int answer = 0;

	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = i + 1; j < nums.size(); ++j)
		{
			for (int k = j + 1; k < nums.size(); ++k)
			{
				if (IsPrime(nums[i] + nums[j] + nums[k]) == true) ++answer;
			}
		}
	}

	return answer;
}

/*
3개를 더했을 때 소수가 되는 경우의 개수

완탐으로 소수인 경우를 체크
*/