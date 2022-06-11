#include <iostream>
#include <string>
using namespace std;

int main()
{
	long long int a;
	int b, c, d;
	scanf("%lld %d %d %d", &a, &b, &c, &d);

	for (int i = 1; i < d; ++i)
	{
		a *= b;
		a += c;
	}
	cout << a;
	return 0;
}
