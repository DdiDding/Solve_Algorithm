#include <iostream>
#include <string>
using namespace std;

static const int LENGTH = 19;

int main()
{
	int plane[LENGTH][LENGTH] = { 0 };

	for (int i = 0; i < LENGTH; ++i)
	{
		for (int j = 0; j < LENGTH; ++j)
		{
			int color = 0;
			scanf("%d", &color);

			plane[i][j] = color;
		}
	}

	int reverseCnt = 0;
	scanf("%d", &reverseCnt);

	for (int i = 0; i < reverseCnt; ++i)
	{
		int row = 0, column = 0;
		scanf("%d %d", &row, &column);
		row -= 1; column -= 1;

		//row 계산
		for (int j = 0; j < LENGTH; ++j)
		{
			plane[row][j] = !plane[row][j];
		}
		//column 계산
		for (int j = 0; j < LENGTH; ++j)
		{
			plane[j][column] = !plane[j][column];
		}
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
