#include <iostream>

int main()
{
	char data[21] = {};
	std::cin >> data;

	for (int i = 0; i < 21; ++i)
	{
		if(data[i] != NULL)
		std::cout << "\'" << data[i] << "\'" << std::endl;
	}
	return 0;
}
