#include <iostream>
using namespace std;
/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */


void plusMinus(vector<int> arr) {

	int positive = 0, negative = 0, zero = 0, size;

	size = arr.size();
	for (const auto & data : arr)
	{
		data == 0 ? ++zero : data < 0 ? ++negative : ++positive;
	}

	cout << fixed;
	cout.precision(6);
	cout << (float)positive / size << endl;
	cout << (float)negative / size << endl;
	cout << (float)zero / size;
}