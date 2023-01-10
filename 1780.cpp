#include <bits/stdc++.h>
using namespace std;

int s[2190][2190];
int ret[3];

void solve(int y, int x, int len)
{
	//통일 된 종이인지 확인
	int std = s[y][x];
	bool isSame = true;
	for (int i = y; i < y + len && isSame; ++i)
	{
		for (int j = x; j < x + len && isSame; ++j)
		{
			if (std != s[i][j]) isSame = false;
		}
	}

	//기저사례 : 통일 된 종이일 때
	if (isSame == true)
	{
		++ret[std + 1];
		return;
	}

	//아니라면 종이를 9등분
	int l = len / 3;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			solve(y + l * i, x + l * j, l);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> s[i][j];
		}
	}

	solve(0, 0, n);

	for (const auto & d : ret)
	{
		cout << d << '\n';
	}
	return 0;
}

/*
N * N칸에 -1, 0, 1중 하나가 써져있다.

종이가 모두 같은 수로 되어 있다면 종이를 그대로 사용한다.
1이 아닌 경우에는 종이를 같은 크기의 종이 9개로 자르고 위를 반복한다.

*/


//예전 풀이
/*
N x N 행렬로 표현되는 종이
각 칸에는 -1, 0, 1이 저장
규칙에따라 자른다. 

종이가 같은수면 이종이 그대로 사용
아니면 종이를 같은 크기의 종이  9개로 자르고, 각 잘린 종이에 대해 1의 고가저을 반보 

int map[n][n] 의 모든 값이 같으면 사용
아니면 9등분을 한다. 그리고 다시 1번 반복

-1로만 채워진 수, 0으로만 채워진 수, 1로만 채워진 수 구하기

N은3의제곱 꼴 = 9로 자르지 못하는 경우는 없다.

3
9
27
*/
/*
#include <bits/stdc++.h>
using namespace std;

int n;
short maps[2190][2190];
int ret[3];

//x,y는 종이의 각 시작,끝 위치
void Recursive(int yS, int yE, int xS, int xE)
{
	//base case. 1 * 1칸일때 카운팅 후 return

	//1.모든 배열의 원소 값이 같은지 확인

	//2.(true) 해당하는 값에 대한 카운팅, return

	//3.(false) 9구역으로 나누고, 각 구역마다 Recursive실행
}

//N이 9라면 S는 0, E는 8이 들어온다.
void Counting(int yS, int xS, int l)
{
	//모든 타일이 같은지 확인 (자동으로 한칸일때도 적용된다.
	bool isAllSame = true;
	for (int y = yS; (y < yS + l) && isAllSame; ++y)
	{
		for (int x = xS; (x < xS + l) && isAllSame; ++x)
		{
			if (maps[y][x] != maps[yS][xS])
			{
				isAllSame = false;
			}
		}
	}

	//모두 같다면 카운트
	if (isAllSame == true)
	{
		++ret[maps[yS][xS] + 1];
		return;
	}

	//9등분한 배열마다 재귀를 들어간다.
	l /= 3;
	for (int y = 0; y < 3; ++y)
	{
		for (int x = 0; x < 3; ++x)
		{
			Counting(yS + l * y, xS + l * x, l);
		}
	}
	return;
}

int main()
{
	//1. Input values
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;

	for (int y = 0; y < n; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			cin >> maps[y][x];
		}
	}

	//2. Do Recursive
	Counting(0, 0, n);

	//3. Print
	for (const auto & d : ret)
	{
		cout << d << "\n";
	}
	return 0;
}
*/