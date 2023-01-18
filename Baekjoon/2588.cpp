#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int main()
{
	short A, B;
	cin >> A >> B;
	cout << A * (B % 10) << "\n" << A * (B % 100 / 10) << "\n" << A * (B / 100) << "\n" << A * B;

	return 0;
}