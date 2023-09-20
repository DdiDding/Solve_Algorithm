//TODO:DP로 풀어보기! 맞으면 Success로 옮기자!

//완전탐색 성공!
/*
#include <bits/stdc++.h>
using namespace std;


//게임판
char board[5][5] = {
	{'U','R','L','P','M'},
	{'X','P','R','E','T'},
	{'G','I','A','E','T'},
	{'X','T','N','Z','Y'},
	{'X','O','Q','R','S'}
};

//계산하기 쉽게 하기 위한 8방향 배열
const int nx[8] = { 0,1,1,1,0,-1,-1,-1 };
const int ny[8] = { 1,1,0,-1,-1,-1,0,1 };

//글자를 찾았는지 못찾았는지 반환
bool Solve(int x, int y, int idx)
{
	//기저사례 : 모두 다 찾았을 때
	if (idx == word.size()) return true;

	//재귀의 능력 : 현재 좌표에서 8방향을 확인해 글자 찾기
	for (int i = 0; i < 8; ++i)
	{
		///TODO:여기에 범위 벗어난 예외 처리 해야함
		if (board[x + nx[i]][y + ny[i]] == word[idx])
		{
			//찾았다면 다음 글자 찾기
			if (Solve(x + nx[i], y + ny[i], idx + 1) == true) return true;
		}
	}

	return false;
}

int main()
{
	//테스트 케이스의 수
	for (int t = 0; t < 5; ++t)
	{
		cin >> word;

		//첫번째 글자는 for문으로 찾을거임,
		bool bNotFound = true;
		for (int i = 0; i < 5 && bNotFound; ++i)
		{
			for (int j = 0; j < 5 && bNotFound; ++j)
			{
				//찾게되면 그 글자의 좌표를 재귀에 넣고 반환값 받아오기
				if (board[i][j] == word[0])
				{
					if (Solve(i, j, 1) == true) bNotFound = false;
				}
			}
		}

		if (bNotFound == false) cout << word << "를 찾았다!\n\n";
		else cout << word << "를 못 찾았다..\n\n";
	}
	
	//true면 찾음, false면 못찾음
}

*/

//이건 성공전에 틀린 풀이해본거
/*
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
/*
5 * 5 게임판

한글자에서 펜을 움직이면서 만나는 글자를 순서대로 나열해서 영단어 찾기
8방향 모두 움직이기 가능
건너뛸수 없음
지나온 글자 다시 찾기 가능

완전탐색으로 글자 수 만큼 재귀 돌리기

시간 복잡도
8^n-1 = o(8^n)
너무너무 오래걸린다.
*/