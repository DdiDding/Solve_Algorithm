#include <iostream>
#include <string>
using namespace std;
int main()
{
	int a;
	scanf("%X", &a);

	for (int i = 1; i <= 15; ++i)
	{
		printf("%X*%X=%X\n", a, i, a * i);
	}

	return 0;
}
