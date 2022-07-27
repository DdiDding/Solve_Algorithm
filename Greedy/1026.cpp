#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

//결과인 최소 값을 가지려면 큰값 * 작은값 의 연속이어야 하므로 오름차순A, 내림차순B를 곱하면 된다.


int main()
{
	int N, result = 0;
	cin >> N;

	vector<int> A;
	vector<int> B;

	for (int i = 0; i < N; ++i)
	{
		int element;
		cin >> element;
		A.push_back(element);
	}

	for (int i = 0; i < N; ++i)
	{
		int element;
		cin >> element;
		B.push_back(element);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());


	for (int i = 0; i < N; ++i)
	{
		result += A[N - i - 1] * B[i];
	}

	cout << result;

	return 0;
}
