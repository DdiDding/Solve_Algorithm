#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
	int take = nums.size() / 2;
	set<int> s(nums.begin(), nums.end());

	return s.size() < take ? s.size() : take;
}

/*
N마리중 N/2마리 가져가기
가장 다양한 포켓몬 가져가기

1. 종류가 몇개인가?
2. 종류기반으로 답 도출
*/