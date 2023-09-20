//TODO:DP�� Ǯ���! ������ Success�� �ű���!

//����Ž�� ����!
/*
#include <bits/stdc++.h>
using namespace std;


//������
char board[5][5] = {
	{'U','R','L','P','M'},
	{'X','P','R','E','T'},
	{'G','I','A','E','T'},
	{'X','T','N','Z','Y'},
	{'X','O','Q','R','S'}
};

//����ϱ� ���� �ϱ� ���� 8���� �迭
const int nx[8] = { 0,1,1,1,0,-1,-1,-1 };
const int ny[8] = { 1,1,0,-1,-1,-1,0,1 };

//���ڸ� ã�Ҵ��� ��ã�Ҵ��� ��ȯ
bool Solve(int x, int y, int idx)
{
	//������� : ��� �� ã���� ��
	if (idx == word.size()) return true;

	//����� �ɷ� : ���� ��ǥ���� 8������ Ȯ���� ���� ã��
	for (int i = 0; i < 8; ++i)
	{
		///TODO:���⿡ ���� ��� ���� ó�� �ؾ���
		if (board[x + nx[i]][y + ny[i]] == word[idx])
		{
			//ã�Ҵٸ� ���� ���� ã��
			if (Solve(x + nx[i], y + ny[i], idx + 1) == true) return true;
		}
	}

	return false;
}

int main()
{
	//�׽�Ʈ ���̽��� ��
	for (int t = 0; t < 5; ++t)
	{
		cin >> word;

		//ù��° ���ڴ� for������ ã������,
		bool bNotFound = true;
		for (int i = 0; i < 5 && bNotFound; ++i)
		{
			for (int j = 0; j < 5 && bNotFound; ++j)
			{
				//ã�ԵǸ� �� ������ ��ǥ�� ��Ϳ� �ְ� ��ȯ�� �޾ƿ���
				if (board[i][j] == word[0])
				{
					if (Solve(i, j, 1) == true) bNotFound = false;
				}
			}
		}

		if (bNotFound == false) cout << word << "�� ã�Ҵ�!\n\n";
		else cout << word << "�� �� ã�Ҵ�..\n\n";
	}
	
	//true�� ã��, false�� ��ã��
}

*/

//�̰� �������� Ʋ�� Ǯ���غ���
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

	//�׽�Ʈ ���̽���ŭ �ݺ�
	while(n--)
	{
		//������ �Է�
		for (int i = 0; i < MAX; ++i)
		{
			for (int j = 0; j < MAX; ++j)
			{
				cin >> board[i][j];
			}
		}
		
		//�ܾ�� �Է�
		int wn;
		cin >> wn;

		//�ܾ�� ��ŭ �ݺ�
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
5 * 5 ������

�ѱ��ڿ��� ���� �����̸鼭 ������ ���ڸ� ������� �����ؼ� ���ܾ� ã��
8���� ��� �����̱� ����
�ǳʶۼ� ����
������ ���� �ٽ� ã�� ����

����Ž������ ���� �� ��ŭ ��� ������

�ð� ���⵵
8^n-1 = o(8^n)
�ʹ��ʹ� �����ɸ���.
*/