#include <iostream>
using namespace std;

typedef int integer;

void Merge(integer * arr, integer * temp, int start, int mid, int end)
{
	for (int i = start; i <= end; ++i)
	{
		temp[i] = arr[i];
	}

	int part1 = start;
	int part2 = mid + 1;
	int index = start;

	while (part1 <= mid && part2 <= end)
	{
		if (temp[part1] <= temp[part2])
		{
			arr[index] = temp[part1];
			++part1;
		}
		else
		{
			arr[index] = temp[part2];
			++part2;
		}
		++index;
	}

	for (int i = 0; i <= mid - part1; ++i)
	{
		arr[index + i] = temp[part1 + i];
	}
}


void MergeSort(integer * arr, integer * temp, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		MergeSort(arr, temp, start, mid);
		MergeSort(arr, temp, mid + 1, end);
		Merge(arr, temp, start, mid, end);
	}
}

void MergeSort(integer * arr, const int & size)
{
	integer * temp = new integer[size];
	MergeSort(arr, temp, 0, size - 1);
}


int main()
{
	int many = 0;
	cin >> many;
	
	integer * num = new integer[1'000'000];
	for (int i = 0; i < many; ++i)
	{
		cin >> num[i];
	}
	MergeSort(num, many);
	for (int i = 0; i < many; ++i)
	{
		cout << num[i] << '\n';
	}
}
