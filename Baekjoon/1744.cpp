#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<int>arr;
int result = 0;
int i;
int temp;

int main()
{
	//1. Get input & sorting
	ios::sync_with_stdio(0), cin.tie(0);
	
	int N; cin >> N;
	int minUnit = 0;
	
	for (int i = 0; i < N; ++i) 
	{
		cin >> temp;
		
		//if input is one, add to result immediately
		if (temp == 1)
		{
			++result;
		}
		else
		{
			//include zero in the count
			if (temp <= 0) ++minUnit;
			arr.push_back(temp);
		}
	}
	sort(arr.begin(), arr.end(), less<int>());
	N -= result;
	//2. Loop
	//negative part
	if (minUnit != 0)
	{
		//È¦¼ö¸é
		if ((minUnit & 0x1) == 0x1)
		{
			result += arr[minUnit - 1];
		}
		if (2 <= minUnit)
		{
			for (i = 0; i < (minUnit - 1); i += 2)
			{
				result += arr[i] * arr[i + 1];
			}
		}
	}
	
	//positive part
	if (2 <= (N - minUnit))
	{
		for (i = N - 1; minUnit <= i; i -= 2)
		{
			result += arr[i] * arr[i - 1];
		}
		if (minUnit == i) result += arr[i];
	}

	cout << result;
	return 0;
}