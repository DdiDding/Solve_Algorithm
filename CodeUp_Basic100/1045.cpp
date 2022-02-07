#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	long num1;
	long num2;
	std::cin >> num1;
	std::cin >> num2;

	cout << num1 + num2 << endl;
	cout << num1 - num2 << endl;
	cout << num1 * num2 << endl;
	cout << num1 / num2 << endl;
	cout << num1 % num2 << endl;
	cout<<showpoint<< setprecision(3)<<(float)num1 / (float)num2 << endl;

	return 0;
}
