#include <iostream>
using namespace std;

void Swiching(int & a, int & b)
{
	int temp = a;
	a = b;
	b = temp;
}

void BubleSort(int * numList, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 1; j < size - i; ++j)
		{
			if (numList[j - 1] > numList[j])
				Swiching(numList[j], numList[j - 1]);
		}
	}
}

void Print(int * numList, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << numList[i] << '\n';
	}
}

int main()
{
	int many = 0;
	cin >> many;

	int numbers[1001] = { 0 };
	for (int i = 0; i < many; ++i)
	{
		cin >> numbers[i];
	}

	BubleSort(numbers, many);
	Print(numbers, many);
	return 0;
}
