/*
�迭 A,B���� �� �� ���� ���ڸ� �̾� ���Ѵ�.
�迭�� ���̸�ŭ �ݺ��Ѵ�.

�� ���� ���� ���� �����Ͽ� ���Ѵ�.

���� ���� ���� ���� ū ���� ���Ͽ� ���ϸ� ��

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