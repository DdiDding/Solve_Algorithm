#include <iostream>
#include <string>
using namespace std;

struct Position
{
	Position()
	{
		x = 1;
		y = 1;
	}

	int x;
	int y;
};

int main()
{
	Position pos;
	bool bIsMove = false;

	int map[10][10] = { 0 };
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			scanf("%d", &(map[i][j]));
		}
	}


	while (map[pos.y][pos.x] != 2)
	{
		map[pos.y][pos.x] = 9;

		//Move Left
		if (map[pos.y][pos.x + 1] != 1)
		{///장애물이 아니라면
			++pos.x;
		}
		//Move Down
		else if (map[pos.y + 1][pos.x] != 1)
		{///아래로
			++pos.y;
		}
		else if (map[pos.y + 1][pos.x] == 1 && map[pos.y][pos.x + 1] == 1)
		{
			break;
		}
	}
	map[pos.y][pos.x] = 9;

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			printf("%d", map[i][j]);
			if (j != 9) printf(" ");
		}
		printf("\n");
	}

	return 0;
}
