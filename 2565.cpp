#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 101

typedef unsigned int integer;
using namespace std;

int main()
{
	integer N;
	cin >> N;

	vector<pair<integer, integer>> arr;
	integer temp1, temp2;
	for (int i = 0; i < N; ++i)
	{
		cin >> temp1 >> temp2;
		arr.push_back(make_pair(temp1, temp2));
	}
	sort(arr.begin(), arr.end());

	integer dp[MAX];
	integer max = 1;
	for (integer i = 0; i < N; ++i)
	{
		dp[i] = 1;
		for (integer j = 0; j < i; ++j)
		{
			if (arr[j].second < arr[i].second)
			{
				dp[i] = dp[j] + 1 < dp[i] ? dp[i] : dp[j] + 1;
				max = max < dp[i] ? dp[i] : max;
			}
		}
	}

	cout << N - max;
	return 0;
}
