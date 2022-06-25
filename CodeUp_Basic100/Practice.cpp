#include <iostream>
#include <string>
using namespace std;

int main()
{
	int plane[19][19] = { 0 };
	int many;
	scanf("%d", &many);

	for (int i = 0; i < many; ++i)
	{
		int row = 0, column = 0;
		scanf("%d %d", &row, &column);

		plane[row-1][column - 1] = 1;
	}


	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			printf("%d", plane[i][j]);
			if(j != 19) printf(" ");
		}
		printf("\n");
	}

	return 0;
}
