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

	cout << total - max << ' ';
	cout << total - min;
}
