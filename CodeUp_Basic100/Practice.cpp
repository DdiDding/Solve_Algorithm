#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int min = 23;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		scanf("%d", &temp);

		if (temp < min) min = temp;
	}

	printf("%d", min);
	return 0;
}
