#include <string>
#include <vector>

using namespace std;

bool solution(int x) {

	int temp = x;
	int add = 0;
	while (0 < x)
	{
		add += x % 10;
		x /= 10;
	}

	return (temp % add == 0) ? true : false;
}