#include <bits/stdc++.h>
using namespace std;


char m[51][51];

string pre[2]{
	"WBWBWBWB",
	"BWBWBWBW"
};

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int Y, X; cin >> Y >> X;

	for (int i = 1; i <= Y; ++i)
	{
		for (int j = 1; j <= X; ++j)
		{
			cin >> m[j][i];
		}
	}
	
	//전체 보드의 좌표
	int result = 90;
	for (int i = 1; i <= Y - 7; ++i)
	{
		for (int j = 1; j <= X - 7; ++j)
		{

			//흑백 반복
			for (int t = 0; t < 2; ++t)
			{
				int cnt = 0;
				bool bh = t;

				//cout << (bh ? "흑색부터 비교합니다." : "백색부터 비교합니다.") << endl;
				//비교하려는 좌표
				for (int b = 0; b <  8; ++b)
				{
					for (int a = 0; a < 8; ++a)
					{
						//cout << "기준인 " << pre[bh][a] << "와 보드판의 " << m[j + b][i + a];
						if (pre[bh][a] != m[j + b][i + a])
						{
							//cout << "다르므로 카운팅합니다." << endl;
							++cnt;
						}
						else
						{
							//cout << "같으므로 넘어갑니다." << endl;
						}
					}
					bh = !bh;
				}
				result = min(result, cnt);
			}
		}
	}
	cout << result;
	return 0;
}


/*
m * n의 보드
검은색 or 흰색으로 랜덤으로 칠해짐

잘라서  8 * 8체스판으로 만드려고함
사방은 다른 색깔

one index 하자

각 꼭짓점부터
X - 8
Y - 8

8-8

0 1 2 3 4 5 6 7

one Index <= X - 7

X가 13이면
1  <= 13 - 8 = 5

Y가 10 이면
1 <= 10 -8

즉 N - 8 * M - 8  N과 M의 최대가 같으니 결국엔 N^2

중복검사 = 7 * 7 = 49

50 * 50 * 49 * 2 (흑백)

125000 정도네 ㄱㅊ을듯

입력값은 Y, X순

*/