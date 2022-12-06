#include <bits/stdc++.h>
using namespace std;
int y, x;
int checkSet[8] = { 0,1,2,3,3,4,4,5 };

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> y >> x;

	if (y == 1) cout << 1;
	if (y == 2)
	{
		if (x < 7) cout << (x + 1) / 2;
		else cout << 3;
	}
	
	if (2 < y)
	{
		if (x < 8) cout << checkSet[x];
		else cout << 5 + (x - 7);
	}

	return 0;
}
/*
N * M 체스판

병든 나이트
2칸 위로, 1칸 오른쪽
1칸 위로, 2칸 오른쪽
1칸 아래로, 2칸 오른쪽
2칸 아래로, 1칸 오른쪽

세로가 한 칸이면 이동 불가, 기본 1칸


세로가 두 칸일때 
제약 없음 : 1, 2 = 1
			3, 4 = 2
			5, 6 = 3
제약 있음 : 못만듬


세로가 세 칸이상이면 가로만큼 한칸씩 이동할수 있다.
제약 없음 : 
8칸이상일때 제약 있음 : 

12개
10개
ㅁㅇㅁㅁㅁㅁㅁ|
ㅁㅁㅁㅁㅇㅁㅁ|
ㅇㅁㅇㅁㅁㅁㅇ|
7칸까지는 5개

나이트의 이동횟수가 4번이상이면 이동방법을 모두 한번씩 사용해야한다.

문제 못읽음
*/