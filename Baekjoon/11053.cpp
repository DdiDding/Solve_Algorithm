#include<iostream>
#define MAX 1'001

typedef unsigned int integer;
using namespace std;

int main()
{
	integer N;
	cin >> N;
	
	integer arr[MAX];
	integer dp[MAX];
	integer max = 1;
	//[��� �迭�� �ѹ� ���� �ݺ���] ���� ������ ���ʰ� �� ���� �����Ѵ�. 
	for (integer i = 0; i < N; ++i)
	{
		dp[i] = 1;
		cin >> arr[i];
		for (integer j = 0; j < i; ++j)
		{
			if (arr[j] < arr[i])
			{///���� �ε����� �� ũ�ٸ� dp�� ������Ʈ
				dp[i] = dp[j] + 1 < dp[i] ? dp[i] : dp[j] + 1;
				max = max < dp[i] ? dp[i] : max;
			}
		}
	}

	cout << max;
	return 0;
}
