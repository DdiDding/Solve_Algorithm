#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int arr[52];

int main()
{
	//1. Get input & sorting
	ios::sync_with_stdio(0), cin.tie(0);
	
	int N; cin >> N;
	int minUnit = 0;
	for (int i = 0; i < N; ++i) 
	{
		cin >> arr[i];
		//include zero in the count
		if (arr[i] <= 0) --minUnit;
	}

	sort(arr, arr + N + 1, greater<int>());

	//2. Loop
	for (int i = 0; i < minUnit; ++i)
	{

	}
	return 0;
}