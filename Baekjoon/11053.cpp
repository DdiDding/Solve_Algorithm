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
	//[모든 배열을 한번 도는 반복문] 증가 수열의 시초가 될 수를 선택한다. 
	for (integer i = 0; i < N; ++i)
	{
		dp[i] = 1;
		cin >> arr[i];
		for (integer j = 0; j < i; ++j)
		{
			if (arr[j] < arr[i])
			{///현재 인덱스가 더 크다면 dp값 업데이트
				dp[i] = dp[j] + 1 < dp[i] ? dp[i] : dp[j] + 1;
				max = max < dp[i] ? dp[i] : max;
			}
		}
	}

	cout << max;
	return 0;
}
