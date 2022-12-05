#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> maps;
int ret[3];

//N이 9라면 S는 0, E는 8이 들어온다.
void Counting(int yS, int yE, int xS, int xE)
{
	//모든 타일이 같은지 확인 (자동으로 한칸일때도 적용된다.
	bool isAllSame = true;
	int std = maps[yS][xS];

	for (int y = yS; y <= yE; ++y)
	{
		for (int x = xS; x <= xE; ++x)
		{
			if (maps[y][x] != std)
			{
				isAllSame = false;
				break;
			}
		}
		if (isAllSame == false) break;
	}
	
	//모두 같으면 카운팅, 종료
	if (isAllSame == true)
	{
		ret[maps[yS][xS] + 1] += 1;
		return;
	}
	
	//9등분한 배열마다 재귀를 들어간다.
	int divStd = (yE - yS) / 3 + 1;
	for (int y = 0; y < 3; ++y)
	{
		int tempS_y = yS + (divStd * y);
		for (int x = 0; x < 3; ++x)
		{
			int tempS_x = xS + (divStd * x);
			Counting(tempS_y, tempS_y + divStd - 1, tempS_x, tempS_x + divStd - 1);
		}
	}
	return;
}

int main()
{
	//1. Input values
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;

	maps.resize(n + 1);
	for (int y = 0; y < n; ++y)
	{
		maps[y].resize(n + 1);
		for (int x = 0; x < n; ++x)
		{
			int temp; cin >> temp;
			maps[y][x] = temp;
		}
	}
	
	//2. Do Recursive
	Counting(0, n - 1, 0, n - 1);

	//3. Print
	for (const auto & d : ret)
	{
		cout << d << "\n";
	}
	return 0;
}

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

부분문제를


**/