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
		cout << numList[i] << endl;
	}
}

int main()
{
	int numbers[3];
	cin >> numbers[0] >> numbers[1] >> numbers[2];
	BubleSort(numbers, 3);
	Print(numbers, 3);
	return 0;
}
