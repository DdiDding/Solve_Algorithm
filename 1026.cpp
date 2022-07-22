#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

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
