#include <bits/stdc++.h>
using namespace std;

const int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
const int dy[8] = { 1,1,0,-1,-1,-1,0,1 };

//zero-based
char board[51][51];
int MAX = 5;

bool InRange(int y, int x)
{
	if (y < 0 || MAX <= y || x < 0 || MAX <= x) return false;
	return true;
}

bool hasWord(int y, int x, const string & word)
{
	if (InRange(y, x) == false) return false;
	if (board[y][x] != word[0]) return false;
	if (word.size() == 1) return true;

	for (int dir = 0; dir < 8; ++dir)
	{
		int nY = y + dy[dir];
		int nX = x + dx[dir];

		if (hasWord(nY, nX, word.substr(1))) return true;
	}

	return false;
}

int main()
{
	int n;
	cin >> n;

	//테스트 케이스만큼 반복
	while(n--)
	{
		//보드판 입력
		for (int i = 0; i < MAX; ++i)
		{
			for (int j = 0; j < MAX; ++j)
			{
				cin >> board[i][j];
			}
		}
		
		//단어개수 입력
		int wn;
		cin >> wn;

		//단어개수 만큼 반복
		while (wn--)
		{
			string word;
			cin >> word;

			bool result = false;

			for (int i = 0; i < MAX; ++i)
			{
				for (int j = 0; j < MAX; ++j)
				{
					result = hasWord(i, j, word);
					if (result == true) break;
				}
				if (result == true) break;
			}

			cout << word << (result ? " YES\n" : " NO\n");
		}
	}

	return 0;
}

/*
5 * 5 게임판

한글자에서 펜을 움직이면서 만나는 글자를 순서대로 나열해서 영단어 찾기
8방향 모두 움직이기 가능
건너뛸수 없음
지나온 글자 다시 찾기 가능

완전탐색으로 글자 수 만큼 재귀 돌리기

*/