#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

#define MAX 999999999
using namespace std;

int ret;
int clocks[16];
vector<int> lists[10] = {{0,1,2},{3,7,9,11},{4,10,14,15},{0,4,5,6,7},
{6,7,8,10,12},{0,2,14,15},{3,14,15},{4,5,7,14,15},{1,2,3,4,5},{3,4,5,9,13}};

void Print()
{
	for (auto d : clocks)
	{
		cout << d << " ";
	}
	cout << endl;
}

//idx : 스위치의 인덱스
//cnt : 스위치를 누른 카운트
void Counting(int idx, int cnt)
{
	//모든 시계가 12시를 가르킬 때 result 최신화
	if (accumulate(clocks, clocks + 16, 0) == 12 * 16)
	{
		ret = min(ret, cnt);
	}

	//base case
	//처음부터 마지막 스위치까지 탐색했을 때
	if (9 < idx) return;

	//step - 현재 스위치를 0 ~ 4번 누른다.
	for (int i = 0; i < 4; ++i)
	{
		//스위치에 해당하는 모든 시계 시간 추가
		if (0 < i)
		{
			for (auto & d : lists[idx])
			{
				clocks[d] = (clocks[d] + 3) % 12;
				if (clocks[d] == 0) clocks[d] = 12;
			}
		}
		Counting(idx + 1, cnt + i);
	}

	//마지막으로 9시간이 늘어났으니 9시간을 다시 빼준다.
	for (auto & d : lists[idx])
	{
		clocks[d] -= 9;
		if (clocks[d] <= 0) clocks[d] += 12;
	}
	return;
}

int main()
{
	int c; cin >> c;
	while (c--)
	{
		for (int i = 0; i < 16; ++i)
		{
			cin >> clocks[i];
		}

		ret = MAX;
		Counting(0, 0);
		cout << (ret == MAX ? -1 : ret) << '\n';
	}
	return 0;
}


/*
4 * 4형태의 배치된 16개의 시계
12, 3, 6, 9 시중 하나를 가르킨다.
스위치 10개가 있고 스위치를 누르면 3시간씩 움직인다.

모든시계를 12시로 돌려라

무수한 경우의 수, 그중 하나의 조건이 맞는 정답 = 최적화 문제
일단 완탐해본다.
스위치 하나당 4번 돌릴수있다.(스위치를 누르지 않는것도 포함)
스위치는 총 10개니까
4^10개의 경우의 수가 나온다.
??로 충분히 가능하다
=방법 설정했고


계획?
재귀의 사이즈는 스위치의 개수인 10이다. (반복횟수가아님)
현재 스위치를 0,1,2,3 눌렀을때 다음 스위치로 넘어갈것.



BASE : 모든 시계가 12시를 가르킨다.

STEP : 스위치를 누르면 해당 시계가 움직인다.
모든 스위치를 누르면 모든 시계가 움직인다.

BASE	: 재귀안의 반복문을 뜻한다.
RESULT

n은 스위치 개수


*/