#include <iostream>
#include <stdio.h>
#define MAX 101
typedef unsigned short pos;
using namespace std;

bool maze[MAX][MAX];
struct Position
{
	Position() {}
	Position(pos x, pos y)
		:X(x),Y(y)
	{}
	unsigned short X;
	unsigned short Y;
};

int main()
{
	Position end;
	cin >> end.Y >> end.X;

	for (int i = 1; i <= end.Y; ++i)
	{
		for (int j = 1; j <= end.X; ++j)
		{
			scanf("%1d", &maze[i][j]);
		}
	}

	cout << DFS(Position(1,1),Position(1,1),end,0)<<endl;
	cout << min;

	return 0;
}