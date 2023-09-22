/*
배열 A,B에서 각 한 개의 숫자를 뽑아 곱한다.
배열의 길이만큼 반복한다.

두 수를 곱한 값을 누적하여 더한다.

가장 작은 값과 가장 큰 값을 곱하여 더하면 됨

*/
#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
	sort(A.begin(), A.end(), less<int>());
	sort(B.begin(), B.end(), greater<int>());

	int answer = 0;
	for (int i = 0; i < A.size(); ++i)
	{
		answer += A[i] * B[i];
	}

	return answer;
}