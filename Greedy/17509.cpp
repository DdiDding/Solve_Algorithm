#include <bits/stdc++.h>
using namespace std;
#define MAX 11

//시간이 작고, 오답판정이 많은걸 먼저 해야한다.
typedef pair<int, int> pii;
#define Time first
#define Verdict second

//기준점 맨 첫번쨰는 b다.
bool comp(const pii & a, const pii & b)
{
	return a.Time < b.Time;
}

pii p[MAX];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	for (int i = 0; i < MAX; ++i)
	{
		cin >> p[i].Time >> p[i].Verdict;
	}
	sort(p, p + MAX, comp);

	int result = 0;
	int time = 0;
	for (auto data : p)
	{
		time += data.Time;
		result += time + (data.Verdict * 20);
	}

	cout << result;
	return 0;
}

/*
T분동안 문제를 푼다면
감점 : T + 20V
V는 오답판정의 개수
(컴파일 에러를 제외)

시험이 끝날때까지 문제를 못풀면,
패널티가 없다? ㅋㅋ

나쁜소식 :

우리는 문제해결에 얼마나 시간이 걸릴지 예측할 수 있다.
그리고 오답판정의 개수도 알 수 있다.

모든 문제를 풀때 최소한의 패널티는?

시간이 누적되는게 핵심 최소 결과값은?

10 - 2, 20 - 2

시간이 작은거먼저해볼까?

//작은걸 먼저 할 경우
10 - 2 = 10 + 40 = 50
30 - 2 = 30 + 40 = 70
				 = 50 + 70 = 120

//큰걸 먼저 할 경우
20 - 2 = 20 + 40 = 60
30 - 2 = 30 + 40 = 70
				 = 60 + 70 = 130


10 - 1 , 10 - 2 에서
//오답판정이 많은거 먼저 할 경우
10 - 2 = 10 + 40 = 50
20 - 1 = 10 + 20 = 30
= 80

//오답판정이 작은거 먼저 할 경우
10 - 1 = 10 + 20 = 30
20 - 2 = 20 + 40 = 60
= 90

시간이 작고, 오답판정이 많은걸 먼저 해야한다.

sort후 순차탐색으로 합하면 됨 - n log n

300  * 11 = 3300

3300 * 2000 = 6'600'000 int로 충분

11줄이 주어짐
1<= D는 문제해결 시간, 0<= V <= 1000 는 몇개의 오답판정인지

20 + 200 = 220
40 + 60	 = 100
60 + 20  = 80
90
120
150
170
190
200
210
220

220 + 100 + 80 = 400
1210 1510

*/