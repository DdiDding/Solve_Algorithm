#include <iostream>
#include <vector>

using namespace std;
/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void miniMaxSum(vector<int> arr) {

	int min = arr[0], max = arr[0], total = 0;
	for (const auto & data : arr)
	{
		total += data;
		if (data < min) min = data;
		if (max < data) max = data;
	}

	cout << total - min;
	cout << total - max << ' ';
}

void main()
{
	vector<int> arr(5,0);
	for (int i = 0; i < 5; ++i)
	{
		cin >> arr[i];
	}

	miniMaxSum(arr);

	return;
}