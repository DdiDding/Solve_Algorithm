#include <iostream>
#include <string>
using namespace std;


int main()
{
	int row = 0, column = 0;
	scanf("%d %d", &column, &row);
	int plane[101][101] = { 0 };

	int stickCnt = 0;
	scanf("%d", &stickCnt);

	for (int i = 0; i < stickCnt; ++i)
	{
		int length = 0, direction = 0, x = 0, y = 0;
		scanf("%d %d %d %d", &length, &direction, &y, &x);
		x -= 1; y -= 1;

		for (int j = 0; j < length; ++j)
		{
			if (direction == 0)
			{
				plane[y][x + j] = 1;
			}
			else
			{
				plane[y + j][x] = 1;
			}
		}
	}


	for (int i = 0; i < column; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			printf("%d", plane[i][j]);
			if(j != row) printf(" ");
		}
		printf("\n");
	}

	return 0;
}
